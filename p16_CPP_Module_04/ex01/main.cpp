#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();


        delete meta;
        delete j;
        delete i;
    }

    {
        Dog d;
        Cat c;

        const Animal& a1 = d;
        const Animal& a2 = c;

        std::cout << "a1 type: " << a1.getType() << std::endl;
        std::cout << "a2 type: " << a2.getType() << std::endl;

        a1.makeSound();
        a2.makeSound();
    }

    {
        Dog d1;
        Dog d2(d1);
        Dog d3;
        d3 = d1;

        Cat c1;
        Cat c2(c1);
        Cat c3;
        c3 = c1;

        std::cout << "d1 type: " << d1.getType() << std::endl;
        std::cout << "d2 type: " << d2.getType() << std::endl;
        std::cout << "d3 type: " << d3.getType() << std::endl;

        std::cout << "c1 type: " << c1.getType() << std::endl;
        std::cout << "c2 type: " << c2.getType() << std::endl;
        std::cout << "c3 type: " << c3.getType() << std::endl;

        d1.makeSound();
        c1.makeSound();
    }

    {
        const WrongAnimal* wa = new WrongAnimal();
        const WrongAnimal* wc_as_wa = new WrongCat();

        std::cout << "wa type: " << wa->getType() << std::endl;
        std::cout << "wc_as_wa type: " << wc_as_wa->getType() << std::endl;

        wa->makeSound();
        wc_as_wa->makeSound();

        const WrongCat* wc = new WrongCat();
        wc->makeSound();

        delete wa;
        delete wc_as_wa;
        delete wc;
    }

    return 0;
}