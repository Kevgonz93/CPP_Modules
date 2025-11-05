#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y)) {
	// std::cout << "Point Parameterized constructor called" << std::endl;
}

Point::Point(Point const &other) : x(other.getX()), y(other.getY()) {
	// std::cout << "Point Copy constructor called" << std::endl;
}

Point::~Point() {
	// std::cout << "Point Destructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
	(void)other;
	// std::cout << "Point Copy assignment operator called" << std::endl;
	return *this;
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}
