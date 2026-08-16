#include "RPN.hpp"

#include <cctype>
#include <sstream>

RPN::RPN() : _values() {}

RPN::RPN(const RPN& other) : _values(other._values) {}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    _values = other._values;
  }
  return *this;
}

RPN::~RPN() {}

bool RPN::evaluate(const std::string& expr, int& result) {
  _values = std::stack<int>();  // ayni nesne tekrar kullanilabilsin

  std::istringstream iss(expr);
  std::string token;

  while (iss >> token) {
    if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
      _values.push(token[0] - '0');
      continue;
    }

    if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
      if (!applyOperator(token[0])) {
        return false;
      }
      continue;
    }

    return false;
  }

  if (_values.size() != 1) {
    return false;
  }

  result = _values.top();
  return true;
}

bool RPN::applyOperator(char op) {
  if (_values.size() < 2) {
    return false;
  }

  int rhs = _values.top();
  _values.pop();
  int lhs = _values.top();
  _values.pop();

  if (op == '+') {
    _values.push(lhs + rhs);
  } else if (op == '-') {
    _values.push(lhs - rhs);
  } else if (op == '*') {
    _values.push(lhs * rhs);
  } else if (op == '/') {
    if (rhs == 0) {
      return false;
    }
    _values.push(lhs / rhs);
  } else {
    return false;
  }

  return true;
}
