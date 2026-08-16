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

  bool evaluate(const std::string& expr, int& result);

 private:
  // Operandlar burada birikir; operator gelince tepeden iki tane cekilir.
  std::stack<int> _values;

  bool applyOperator(char op);
};

#endif
