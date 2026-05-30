#include "BitcoinExchange.hpp"

#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() : _rates() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    _rates = other._rates;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& dbPath) {
  std::ifstream file(dbPath.c_str());
  if (!file) {
    return false;
  }

  _rates.clear();

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty()) {
      continue;
    }
    if (line.find("date") != std::string::npos &&
        line.find("exchange_rate") != std::string::npos) {
      continue;
    }

    size_t comma = line.find(',');
    if (comma == std::string::npos) {
      continue;
    }

    std::string date = trim(line.substr(0, comma));
    std::string rateStr = trim(line.substr(comma + 1));

    if (!isValidDate(date)) {
      continue;
    }

    double rate = 0.0;
    if (!parseValue(rateStr, rate)) {
      continue;
    }
    if (rate < 0.0) {
      continue;
    }

    _rates[date] = rate;
  }

  return true;
}

void BitcoinExchange::processLine(const std::string& line) const {
  std::string trimmed = trim(line);
  if (trimmed.empty()) {
    return;
  }
  if (trimmed == "date | value") {
    return;
  }

  size_t sep = line.find('|');
  if (sep == std::string::npos || line.find('|', sep + 1) != std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }

  std::string date = trim(line.substr(0, sep));
  std::string valueStr = trim(line.substr(sep + 1));

  if (date.empty() || valueStr.empty() || !isValidDate(date)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }

  double value = 0.0;
  if (!parseValue(valueStr, value)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }
  if (value < 0.0) {
    std::cout << "Error: not a positive number." << std::endl;
    return;
  }
  if (value > 1000.0) {
    std::cout << "Error: too large a number." << std::endl;
    return;
  }

  double rate = 0.0;
  if (!getRateForDate(date, rate)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }

  std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}

std::string BitcoinExchange::trim(const std::string& s) {
  size_t start = 0;
  while (start < s.size() &&
         std::isspace(static_cast<unsigned char>(s[start]))) {
    ++start;
  }
  size_t end = s.size();
  while (end > start &&
         std::isspace(static_cast<unsigned char>(s[end - 1]))) {
    --end;
  }
  return s.substr(start, end - start);
}

bool BitcoinExchange::parseDateParts(const std::string& date, int& year,
                                     int& month, int& day) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
    return false;
  }
  for (size_t i = 0; i < date.size(); ++i) {
    if (i == 4 || i == 7) {
      continue;
    }
    if (!std::isdigit(static_cast<unsigned char>(date[i]))) {
      return false;
    }
  }

  year = std::atoi(date.substr(0, 4).c_str());
  month = std::atoi(date.substr(5, 2).c_str());
  day = std::atoi(date.substr(8, 2).c_str());
  return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
  int year = 0;
  int month = 0;
  int day = 0;
  if (!parseDateParts(date, year, month, day)) {
    return false;
  }

  if (year < 0 || month < 1 || month > 12 || day < 1) {
    return false;
  }

  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && isLeapYear(year)) {
    daysInMonth[1] = 29;
  }

  if (day > daysInMonth[month - 1]) {
    return false;
  }

  return true;
}

bool BitcoinExchange::isLeapYear(int year) {
  if (year % 4 != 0) {
    return false;
  }
  if (year % 100 != 0) {
    return true;
  }
  return (year % 400 == 0);
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& value) {
  if (valueStr.empty()) {
    return false;
  }

  errno = 0;
  char* end = NULL;
  const char* cstr = valueStr.c_str();
  double parsed = std::strtod(cstr, &end);

  if (cstr == end) {
    return false;
  }
  if (*end != '\0') {
    return false;
  }
  if (errno == ERANGE) {
    value = parsed;
    return true;
  }

  value = parsed;
  return true;
}

bool BitcoinExchange::getRateForDate(const std::string& date,
                                     double& rate) const {
  if (_rates.empty()) {
    return false;
  }

  std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
  if (it == _rates.end()) {
    --it;
    rate = it->second;
    return true;
  }

  if (it->first == date) {
    rate = it->second;
    return true;
  }

  if (it == _rates.begin()) {
    return false;
  }

  --it;
  rate = it->second;
  return true;
}
