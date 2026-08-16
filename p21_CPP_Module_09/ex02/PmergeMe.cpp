#include "PmergeMe.hpp"

#include <cctype>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

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

void PmergeMe::run() {
  std::cout << "Before:";
  for (size_t i = 0; i < _vec.size(); ++i) {
    std::cout << " " << _vec[i];
  }
  std::cout << std::endl;
}
