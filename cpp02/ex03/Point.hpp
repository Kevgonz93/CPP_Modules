#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"


class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point& other);
		~Point();
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
};

#endif
