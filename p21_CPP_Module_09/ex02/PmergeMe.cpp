#include "PmergeMe.hpp"

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

bool PmergeMe::parse(int argc, char** argv) {
  (void)argv;
  return argc >= 2;
}

void PmergeMe::run() {}
