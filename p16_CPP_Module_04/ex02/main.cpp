#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testAbstract() {
    std::cout << "\n=== Abstract Test ===" << std::endl;
    // Animal animal; // Error: abstract class
    Animal* dog = new Dog();
    dog->makeSound();
    delete dog;
}

void testBasic() {
    std::cout << "\n=== Basic Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;
}

void testArray() {
    std::cout << "\n=== Array Test ===" << std::endl;
    const int size = 4;
    Animal* animals[size];
    for (int k = 0; k < size / 2; ++k) {
        animals[k] = new Dog();
    }
    for (int k = size / 2; k < size; ++k) {
        animals[k] = new Cat();
    }
    for (int k = 0; k < size; ++k) {
        animals[k]->makeSound();
    }
    for (int k = 0; k < size; ++k) {
        delete animals[k];
    }
}

void testDeepCopy() {
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Bone");
    {
        Dog copy = original;
        copy.getBrain()->setIdea(0, "Changed");
        std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Brains differ: " << (original.getBrain() != copy.getBrain()) << std::endl;
    }
    Cat catOriginal;
    catOriginal.getBrain()->setIdea(0, "Fish");
    {
        Cat catCopy = catOriginal;
        catCopy.getBrain()->setIdea(0, "Changed");
        std::cout << "Cat original: " << catOriginal.getBrain()->getIdea(0) << std::endl;
        std::cout << "Brains differ: " << (catOriginal.getBrain() != catCopy.getBrain()) << std::endl;
    }
}

void testAssignment() {
    std::cout << "\n=== Assignment Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Idea1");
    Dog dog2;
    dog2 = dog1;
    dog1.getBrain()->setIdea(0, "Modified");
    std::cout << "Dog2: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brains differ: " << (dog1.getBrain() != dog2.getBrain()) << std::endl;
}

int main() {
    testAbstract();
    testBasic();
    testArray();
    testDeepCopy();
    testAssignment();
    return 0;
}