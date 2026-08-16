#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

// Ayni sayi dizisini Ford-Johnson (merge-insertion) algoritmasiyla
// iki farkli container uzerinde siralar ve surelerini karsilastirir.
class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  // argv[1..argc-1] sayilari _vec ve _deq'e yazar. Gecersiz girdide false.
  bool parse(int argc, char** argv);

  // Iki container'i da sirala, sonuclari ve sureleri yazdir.
  void run();

 private:
  std::vector<int> _vec;
  std::deque<int> _deq;
};

#endif
