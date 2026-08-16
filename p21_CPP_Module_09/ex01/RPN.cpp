#include "RPN.hpp"

#include <cctype>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
  (void)other;
}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    (void)other;
  }
  return *this;
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string& expr, long long& result) const {
  std::istringstream iss(expr);
  std::string token;
  std::stack<long long> values;

  while (iss >> token) {
    if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
      values.push(static_cast<long long>(token[0] - '0'));
      continue;
    }

    if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
      if (!applyOperator(token[0], values)) {
        return false;
      }
      continue;
    }

    return false;
  }

  if (values.size() != 1) {
    return false;
  }

  result = values.top();
  return true;
}

bool RPN::applyOperator(char op, std::stack<long long>& values) const {
  if (values.size() < 2) {
    return false;
  }

  long long rhs = values.top();
  values.pop();
  long long lhs = values.top();
  values.pop();

  if (op == '+') {
    values.push(lhs + rhs);
  } else if (op == '-') {
    values.push(lhs - rhs);
  } else if (op == '*') {
    values.push(lhs * rhs);
  } else if (op == '/') {
    if (rhs == 0) {
      return false;
    }
    values.push(lhs / rhs);
  } else {
    return false;
  }

  return true;
}
