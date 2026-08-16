#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

// Removes spaces at the beginning and end of words.
static std::string trim(const std::string& s) {
  size_t start = 0;
  while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) {
    ++start;
  }
  size_t end = s.size();
  while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
    --end;
  }
  return s.substr(start, end - start);
}

// Is it in the format "YYYY-MM-DD" and is it a real day on the calendar?
static bool isValidDate(const std::string& date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
    return false;
  }
  for (size_t i = 0; i < date.size(); ++i) {
    if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i]))) {
      return false;
    }
  }

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12 || day < 1) {
    return false;
  }

  static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};
  int maxDay = daysInMonth[month - 1];
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    maxDay = 29;
  }
  return day <= maxDay;
}

// Is it all digits? "1.2" -> true, "1.2abc" / "abc" / "" -> false
static bool parseValue(const std::string& s, double& value) {
  std::istringstream iss(s);
  iss >> value;
  return !iss.fail() && iss.eof();
}

// --------------------------------------------------------------------------
// BitcoinExchange
// --------------------------------------------------------------------------

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

// The data.csv format is: "YYYY-MM-DD,kur". Corrupted lines are silently skipped;
// The entry is automatically eliminated because the "date" in the title is not a valid date.
bool BitcoinExchange::loadDatabase(const std::string& path) {
  std::ifstream file(path.c_str());
  if (!file) {
    return false;
  }

  _rates.clear();

  std::string line;
  while (std::getline(file, line)) {
    size_t comma = line.find(',');
    if (comma == std::string::npos) {
      continue;
    }

    std::string date = trim(line.substr(0, comma));
    if (!isValidDate(date)) {
      continue;
    }

    double rate = 0.0;
    if (!parseValue(trim(line.substr(comma + 1)), rate) || rate < 0.0) {
      continue;
    }

    _rates[date] = rate;
  }
  return true;
}

// Input line: "YYYY-MM-DD | value"
void BitcoinExchange::processLine(const std::string& line) const {
  std::string trimmed = trim(line);
  if (trimmed.empty()) {
    return;
  }

 // There must be exactly one '|'.
  size_t sep = trimmed.find('|');
  if (sep == std::string::npos ||
      trimmed.find('|', sep + 1) != std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }

  std::string date = trim(trimmed.substr(0, sep));
  std::string valueStr = trim(trimmed.substr(sep + 1));

  if (date == "date" && valueStr == "value") {
    return;  // title line
  }

  if (!isValidDate(date)) {
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
  if (!findRate(date, rate)) {
    std::cout << "Error: no data available for this date." << std::endl;
    return;
  }

  std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}

// If the date is not available in the database, the closest earlier date will be used.
bool BitcoinExchange::findRate(const std::string& date, double& rate) const {
  // upper_bound: The first record that is EXACTLY larger than date. Going back one step
  // We find the largest date less than or equal to the date (exact match or lower neighbor) from the date.
  std::map<std::string, double>::const_iterator it = _rates.upper_bound(date);
  if (it == _rates.begin()) {
    return false;  // A day even before the oldest date in the database
  }
  --it;
  rate = it->second;
  return true;
}
