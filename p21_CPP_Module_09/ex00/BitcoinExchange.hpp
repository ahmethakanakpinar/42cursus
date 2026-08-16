#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

// It maintains the Bitcoin exchange rate database and processes "date | value" rows.
class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  // The data.csv file is read and the _rates map is filled.
  bool loadDatabase(const std::string& path);

  // Processes a single line from the input file and writes the result (or error) to the output.
  void processLine(const std::string& line) const;

 private:
  // Key: "YYYY-MM-DD", value: current day's rate.
  // Since the map is sorted, the search for "nearest sub-date" takes O(log n).
  std::map<std::string, double> _rates;

  bool findRate(const std::string& date, double& rate) const;
};

#endif
