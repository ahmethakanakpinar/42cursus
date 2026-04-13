#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data original;
	original.id = 42;
	original.name = "ahmet";

	std::cout << "=== Before Serialization ===" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "id:      " << original.id << std::endl;
	std::cout << "name:    " << original.name << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized (uintptr_t): " << raw << std::endl;

	Data *result = Serializer::deserialize(raw);

	std::cout << "\n=== After Deserialization ===" << std::endl;
	std::cout << "Address: " << result << std::endl;
	std::cout << "id:      " << result->id << std::endl;
	std::cout << "name:    " << result->name << std::endl;

	std::cout << "\nPointers match: " << (result == &original ? "yes" : "no") << std::endl;

	return 0;
}
