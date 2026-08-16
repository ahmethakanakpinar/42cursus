#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
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

  // --- Ford-Johnson, std::vector uzerinde ---
  void sortVector(std::vector<int>& v);
  void insertPendVector(std::vector<int>& chain, const std::vector<int>& pend);
  size_t binarySearchVector(const std::vector<int>& chain, int value,
                            size_t hi) const;

  // --- Ford-Johnson, std::deque uzerinde (ayni algoritmanin ikizi) ---
  void sortDeque(std::deque<int>& d);
  void insertPendDeque(std::deque<int>& chain, const std::deque<int>& pend);
  size_t binarySearchDeque(const std::deque<int>& chain, int value,
                           size_t hi) const;
};

#endif
