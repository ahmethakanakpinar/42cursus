#include "RPN.hpp"

#include <cctype>
#include <sstream>

// Token tek haneli bir sayi mi? (subject: sayilar her zaman 10'dan kucuk)
static bool isNumberToken(const std::string& token) {
  return token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]));
}

// Token destekledigimiz dort operatorden biri mi?
static bool isOperatorToken(const std::string& token) {
  if (token.size() != 1) {
    return false;
  }
  return token[0] == '+' || token[0] == '-' || token[0] == '*' ||
         token[0] == '/';
}

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
    if (isNumberToken(token)) {
      _values.push(token[0] - '0');
      continue;
    }
    if (!isOperatorToken(token)) {
      return false;  // tanimsiz token: harf, parantez, cok haneli sayi...
    }
    if (!applyOperator(token[0])) {
      return false;  // yeterli operand yok ya da sifira bolme
    }
  }

  // Gecerli bir ifadenin sonunda yiginda tek bir sonuc kalir.
  if (_values.size() != 1) {
    return false;
  }

  result = _values.top();
  return true;
}

// Yigindan iki operand ceker, islemi uygular, sonucu geri iter.
// Buraya sadece isOperatorToken'dan gecmis bir karakter gelebilir.
bool RPN::applyOperator(char op) {
  if (_values.size() < 2) {
    return false;
  }

  // Dikkat: once cekilen tepedeki deger sagdaki operand.
  int rhs = _values.top();
  _values.pop();
  int lhs = _values.top();
  _values.pop();

  if (op == '/' && rhs == 0) {
    return false;
  }

  if (op == '+') {
    _values.push(lhs + rhs);
  } else if (op == '-') {
    _values.push(lhs - rhs);
  } else if (op == '*') {
    _values.push(lhs * rhs);
  } else {
    _values.push(lhs / rhs);
  }
  return true;
}
