#include <fstream>
#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  BitcoinExchange btc;
  if (!btc.loadDatabase("data.csv")) {
    std::cout << "Error: could not open database." << std::endl;
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(input, line)) {
    btc.processLine(line);
  }

  return 0;
}
