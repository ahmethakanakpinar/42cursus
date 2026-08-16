#include "PmergeMe.hpp"

#include <sys/time.h>

#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

// Mikrosaniye cozunurluklu saat. std::clock() cok kaba (~10 ms) kalirdi,
// <chrono> ise C++11 oldugu icin kullanilamiyor.
static double nowMicroseconds() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return static_cast<double>(tv.tv_sec) * 1000000.0 +
         static_cast<double>(tv.tv_usec);
}

// Token gecerli bir pozitif tamsayi mi? Sadece rakam kabul edildigi icin
// "-1", "+5", "abc", "3.5" hepsi elenir. Tasma da burada yakalanir.
static bool parseNumber(const char* token, int& value) {
  std::string s(token);
  if (s.empty()) {
    return false;
  }
  for (size_t i = 0; i < s.size(); ++i) {
    if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
      return false;
    }
  }

  std::istringstream iss(s);
  long parsed = 0;
  iss >> parsed;
  if (iss.fail() || !iss.eof() || parsed > INT_MAX) {
    return false;
  }

  value = static_cast<int>(parsed);
  return true;
}

PmergeMe::PmergeMe() : _vec(), _deq() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    _vec = other._vec;
    _deq = other._deq;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

// Ayni sayilar iki container'a birden yazilir; tekrar eden sayilar
// KORUNUR, cunku girdideki eleman sayisi cikista da ayni olmali.
bool PmergeMe::parse(int argc, char** argv) {
  if (argc < 2) {
    return false;
  }

  for (int i = 1; i < argc; ++i) {
    int value = 0;
    if (!parseNumber(argv[i], value)) {
      return false;
    }
    _vec.push_back(value);
    _deq.push_back(value);
  }
  return true;
}

// chain[0, hi) araliginda value'nun girmesi gereken indeksi bulur.
// Klasik ikili arama: her adimda aralik yariya iner, O(log n) karsilastirma.
size_t PmergeMe::binarySearchVector(const std::vector<int>& chain, int value,
                                    size_t hi) const {
  size_t lo = 0;
  while (lo < hi) {
    size_t mid = lo + (hi - lo) / 2;
    if (chain[mid] < value) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

// pend[i], chain[i] ile eslesen kucuk deger.
// b1 kesin a1'den kucuk oldugu icin aramasiz basa gider. Kalanlar Jacobsthal
// sirasiyla eklenir: bu sira, her eklemede arama araliginin tam bir 2'nin
// kuvvetine oturmasini saglar, yani karsilastirma sayisi en aza iner.
void PmergeMe::insertPendVector(std::vector<int>& chain,
                                const std::vector<int>& pend) {
  size_t m = pend.size();
  if (m == 0) {
    return;
  }

  chain.insert(chain.begin(), pend[0]);

  // pos[i] = a_i'nin zincirdeki GUNCEL indeksi. b_i her zaman a_i'nin
  // solunda kalacagi icin arama ust siniri olarak bunu kullaniyoruz.
  std::vector<size_t> pos(m);
  for (size_t i = 0; i < m; ++i) {
    pos[i] = i + 1;
  }

  // Jacobsthal sayilari: 1, 3, 5, 11, 21, 43...  t(k+1) = t(k) + 2*t(k-1)
  size_t prev = 1;
  size_t curr = 3;
  while (prev < m) {
    size_t last = curr < m ? curr : m;
    for (size_t k = last; k > prev; --k) {  // grup icinde geriye dogru
      size_t i = k - 1;
      size_t p = binarySearchVector(chain, pend[i], pos[i]);
      chain.insert(chain.begin() + static_cast<ptrdiff_t>(p), pend[i]);
      for (size_t j = 0; j < m; ++j) {
        if (pos[j] >= p) {
          ++pos[j];
        }
      }
    }
    size_t next = curr + 2 * prev;
    prev = curr;
    curr = next;
  }
}

// Ford-Johnson (merge-insertion):
//   1) elemanlari ikiserli esle, her esin buyugunu belirle
//   2) buyukleri AYNI algoritmayla sirala (ozyineleme)
//   3) sirali her buyuge esini geri bagla
//   4) kucukleri Jacobsthal sirasiyla ikili aramayla zincire yerlestir
void PmergeMe::sortVector(std::vector<int>& v) {
  if (v.size() < 2) {
    return;
  }

  bool hasOdd = (v.size() % 2 != 0);
  int odd = hasOdd ? v.back() : 0;

  // 1) (buyuk, kucuk) ikilileri
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i + 1 < v.size(); i += 2) {
    if (v[i] > v[i + 1]) {
      pairs.push_back(std::make_pair(v[i], v[i + 1]));
    } else {
      pairs.push_back(std::make_pair(v[i + 1], v[i]));
    }
  }

  // 2) Buyukler ana zinciri olusturur; onlari ozyinelemeli sirala
  std::vector<int> chain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    chain.push_back(pairs[i].first);
  }
  sortVector(chain);

  // 3) Siralama esleri bozdu; her buyugun kucugunu geri bagla.
  //    Buyugun zincirdeki yeri ikili aramayla bulunur; o yer doluysa
  //    (ayni degerden birden fazla varsa) bir saga kayilir.
  std::vector<int> pend(pairs.size(), 0);
  std::vector<bool> taken(chain.size(), false);
  for (size_t j = 0; j < pairs.size(); ++j) {
    size_t k = binarySearchVector(chain, pairs[j].first, chain.size());
    while (taken[k]) {
      ++k;
    }
    taken[k] = true;
    pend[k] = pairs[j].second;
  }

  // 4) Kucukleri yerlestir
  insertPendVector(chain, pend);

  // 5) Es bulamayan tek eleman varsa tum zincirde aranarak eklenir
  if (hasOdd) {
    size_t p = binarySearchVector(chain, odd, chain.size());
    chain.insert(chain.begin() + static_cast<ptrdiff_t>(p), odd);
  }

  v = chain;
}

// Buradan asagisi yukaridaki uc fonksiyonun std::deque ikizi. Subject
// "algoritmayi her container icin ayri implemente et" dedigi icin ortak
// bir sablona indirgenmedi; tekrar bilincli.

size_t PmergeMe::binarySearchDeque(const std::deque<int>& chain, int value,
                                   size_t hi) const {
  size_t lo = 0;
  while (lo < hi) {
    size_t mid = lo + (hi - lo) / 2;
    if (chain[mid] < value) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

void PmergeMe::insertPendDeque(std::deque<int>& chain,
                               const std::deque<int>& pend) {
  size_t m = pend.size();
  if (m == 0) {
    return;
  }

  chain.push_front(pend[0]);

  std::deque<size_t> pos(m);
  for (size_t i = 0; i < m; ++i) {
    pos[i] = i + 1;
  }

  size_t prev = 1;
  size_t curr = 3;
  while (prev < m) {
    size_t last = curr < m ? curr : m;
    for (size_t k = last; k > prev; --k) {
      size_t i = k - 1;
      size_t p = binarySearchDeque(chain, pend[i], pos[i]);
      chain.insert(chain.begin() + static_cast<ptrdiff_t>(p), pend[i]);
      for (size_t j = 0; j < m; ++j) {
        if (pos[j] >= p) {
          ++pos[j];
        }
      }
    }
    size_t next = curr + 2 * prev;
    prev = curr;
    curr = next;
  }
}

void PmergeMe::sortDeque(std::deque<int>& d) {
  if (d.size() < 2) {
    return;
  }

  bool hasOdd = (d.size() % 2 != 0);
  int odd = hasOdd ? d.back() : 0;

  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i + 1 < d.size(); i += 2) {
    if (d[i] > d[i + 1]) {
      pairs.push_back(std::make_pair(d[i], d[i + 1]));
    } else {
      pairs.push_back(std::make_pair(d[i + 1], d[i]));
    }
  }

  std::deque<int> chain;
  for (size_t i = 0; i < pairs.size(); ++i) {
    chain.push_back(pairs[i].first);
  }
  sortDeque(chain);

  std::deque<int> pend(pairs.size(), 0);
  std::deque<bool> taken(chain.size(), false);
  for (size_t j = 0; j < pairs.size(); ++j) {
    size_t k = binarySearchDeque(chain, pairs[j].first, chain.size());
    while (taken[k]) {
      ++k;
    }
    taken[k] = true;
    pend[k] = pairs[j].second;
  }

  insertPendDeque(chain, pend);

  if (hasOdd) {
    size_t p = binarySearchDeque(chain, odd, chain.size());
    chain.insert(chain.begin() + static_cast<ptrdiff_t>(p), odd);
  }

  d = chain;
}

void PmergeMe::run() {
  std::cout << "Before:";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << " " << _vec[i];
  }
  std::cout << std::endl;

  // Sureye kopyalama da dahil: subject "veri yonetimi de dahil" diyor.
  double start = nowMicroseconds();
  std::vector<int> v(_vec);
  sortVector(v);
  double vectorTime = nowMicroseconds() - start;

  start = nowMicroseconds();
  std::deque<int> d(_deq);
  sortDeque(d);
  double dequeTime = nowMicroseconds() - start;

  std::cout << "After:";
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;

  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << vectorTime << " us"
            << std::endl;
  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque : " << dequeTime << " us"
            << std::endl;
}
