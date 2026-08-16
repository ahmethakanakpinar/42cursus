#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
 public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

  bool evaluate(const std::string& expr, long long& result) const;

 private:
  bool applyOperator(char op, std::stack<long long>& values) const;
};

#endif
