#include "Brain.hpp"
Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
}


Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];  // Deep copy: Copy each idea from the other Brain
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];  // Deep copy
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Index out of range: must be between 0 and 99");
    }
    return this->ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= 100) {
        throw std::out_of_range("Index out of range: must be between 0 and 99");
    }
    this->ideas[index] = idea;
}