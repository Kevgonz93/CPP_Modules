#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return "";
	}
	return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index >= 100) {
		return;
	}
	ideas[index] = idea;
}
