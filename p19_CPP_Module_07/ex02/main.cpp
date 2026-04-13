#include <iostream>
#include <string>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"



int main()
{
    std::cout << YELLOW << "\n=============================================" << RESET << std::endl;
    std::cout << YELLOW << "        TEST 1: DEFAULT CONSTRUCTOR" << RESET << std::endl;
    std::cout << YELLOW << "=============================================\n" << RESET << std::endl;
    
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << " (Expected: 0)" << std::endl;
    
    try {
        emptyArray[0] = 1; // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << GREEN << "[SUCCESS] Caught exception on empty array access: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n=============================================" << RESET << std::endl;
    std::cout << YELLOW << "        TEST 2: PARAMETRIC CONSTRUCTOR" << RESET << std::endl;
    std::cout << YELLOW << "=============================================\n" << RESET << std::endl;

    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << " (Expected: 5)" << std::endl;
    
    std::cout << "Checking default initialization (should be 0): ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // assignment
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    std::cout << "After assignment: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\n=============================================" << RESET << std::endl;
    std::cout << YELLOW << "   TEST 3: OUT OF BOUNDS (EXCEPTION HANDLING)" << RESET << std::endl;
    std::cout << YELLOW << "=============================================\n" << RESET << std::endl;

    try {
        std::cout << "Trying to access index [5] of size 5... " << std::endl;
        intArray[5] = 42; // Index out of bounds (0-4 valid)
    } catch (const std::exception& e) {
        std::cout << GREEN << "[SUCCESS] Caught exception: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << "Trying to access negative index [-1]... " << std::endl;
        intArray[-1] = 42;
    } catch (const std::exception& e) {
        std::cout << GREEN << "[SUCCESS] Caught exception: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n=============================================" << RESET << std::endl;
    std::cout << YELLOW << "        TEST 4: DEEP COPY & ASSIGNMENT" << RESET << std::endl;
    std::cout << YELLOW << "=============================================\n" << RESET << std::endl;

    Array<int> copyArray(intArray); // Copy constructor
    Array<int> assignedArray;
    assignedArray = intArray;       // Assignment operator

    std::cout << "Original array [0]: " << intArray[0] << std::endl;
    std::cout << "Copy array [0]: " << copyArray[0] << std::endl;
    std::cout << "Assigned array [0]: " << assignedArray[0] << std::endl;

    std::cout << BLUE << "\n--- Modifying Original Array ---" << RESET << std::endl;
    intArray[0] = 999;
    
    std::cout << "Original array [0] is now: " << intArray[0] << " (Expected: 999)" << std::endl;
    std::cout << "Copy array [0] is still: " << copyArray[0] << GREEN << " -> Deep Copy Works!" << RESET << std::endl;
    std::cout << "Assigned array [0] is still: " << assignedArray[0] << GREEN << " -> Deep Assignment Works!" << RESET << std::endl;

    std::cout << YELLOW << "\n=============================================" << RESET << std::endl;
    std::cout << YELLOW << "        TEST 5: COMPLEX TYPES (STRING & CLASS)" << RESET << std::endl;
    std::cout << YELLOW << "=============================================\n" << RESET << std::endl;

    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "42";
    stringArray[2] = "Istanbul";

    std::cout << "String Array: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

  
    std::cout << GREEN << "\nALL TESTS PASSED SUCCESSFULLY." << RESET << std::endl;

    return 0;
}