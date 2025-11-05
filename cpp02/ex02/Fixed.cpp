#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : rawValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	rawValue = other.rawValue;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	int copyValue = other.getRawBits();
	if (this != &other)
		setRawBits(copyValue);
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return rawValue;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	rawValue = raw;
}

Fixed::Fixed(int const intNum) {
	// std::cout << "Int constructor called" << std::endl;
	rawValue = intNum << fractionalBits;
}

Fixed::Fixed(float const floatNum) {
	// std::cout << "Float constructor called" << std::endl;
	rawValue = static_cast<int>(roundf(floatNum * (1 << fractionalBits)));
}

int Fixed::toInt() const {
	return rawValue >> fractionalBits;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawValue) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// COMPARISON OPERATORS
bool Fixed::operator<(const Fixed& other) const { 
	if (this->getRawBits() < other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed& other) const {
	if (this->getRawBits() <= other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>(const Fixed& other) const { 
	if (this->getRawBits() > other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed& other) const { 
	if (this->getRawBits() >= other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed& other) const {
	if (this->getRawBits() == other.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed& other) const {
	if (this->getRawBits() != other.getRawBits())
		return true;
	else
		return false;
}

// ARITHMETIC OPERATORS
Fixed Fixed::operator+(const Fixed& other) const { 
	return Fixed(this->toFloat() + other.toFloat()); 
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat()); 
}

Fixed Fixed::operator*(const Fixed& other) const { 
	return Fixed(this->toFloat() * other.toFloat()); 
}

Fixed Fixed::operator/(const Fixed& other) const { 
	if (other.getRawBits() == 0)
    	throw std::runtime_error("Division by zero");
	return Fixed(this->toFloat() / other.toFloat()); 
}

// INCREMENT / DECREMENT OPERATORS
Fixed& Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}

Fixed& Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

// MIN / MAX FUNCTIONS
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { 
	if (a > b)
		return a;
	else
		return b;
}
