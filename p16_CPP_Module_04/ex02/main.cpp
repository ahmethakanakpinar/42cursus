#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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
    std::cout << "\n=== Array Test (100 Animals) ===" << std::endl;
    const int size = 100;
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

void testDeepCopyDog() {
    std::cout << "\n=== Deep Copy Test (Dog) ===" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Bone");
    original.getBrain()->setIdea(1, "Walk");

    {
        Dog copy = original;
        std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
        copy.getBrain()->setIdea(0, "Changed in copy");
        std::cout << "Original after change: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Brain addresses: Original " << original.getBrain() << ", Copy " << copy.getBrain() << std::endl;
    }
}

void testDeepCopyCat() {
    std::cout << "\n=== Deep Copy Test (Cat) ===" << std::endl;
    Cat original;
    original.getBrain()->setIdea(0, "Fish");
    original.getBrain()->setIdea(1, "Sleep");

    {
        Cat copy = original;
        std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
        copy.getBrain()->setIdea(0, "Changed in copy");
        std::cout << "Original after change: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Brain addresses: Original " << original.getBrain() << ", Copy " << copy.getBrain() << std::endl;
    }
}

void testAssignment() {
    std::cout << "\n=== Assignment Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Idea1");
    Dog dog2;
    dog2 = dog1;
    std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    dog1.getBrain()->setIdea(0, "Modified");
    std::cout << "Dog2 after mod: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brain addresses: Dog1 " << dog1.getBrain() << ", Dog2 " << dog2.getBrain() << std::endl;
}

int main() {
    testBasic();
    testArray();
    testDeepCopyDog();
    testDeepCopyCat();
    testAssignment();
    return 0;
}