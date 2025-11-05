#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : rawValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	rawValue = other.rawValue;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	int copyValue = other.getRawBits();
	if (this != &other)
		setRawBits(copyValue);
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	rawValue = raw;
}
