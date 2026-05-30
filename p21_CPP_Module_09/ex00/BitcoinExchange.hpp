#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  bool loadDatabase(const std::string& dbPath);
  void processLine(const std::string& line) const;

 private:
  std::map<std::string, double> _rates;

  static std::string trim(const std::string& s);
  static bool parseDateParts(const std::string& date, int& year, int& month,
                             int& day);
  static bool isValidDate(const std::string& date);
  static bool isLeapYear(int year);
  static bool parseValue(const std::string& valueStr, double& value);
  bool getRateForDate(const std::string& date, double& rate) const;
};

#endif