#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <ostream>

class Fixed{
	private:
		int                 rawValue;
		static const int    fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		Fixed(int const intNum);
		Fixed(float const floatNum);

		int     getRawBits() const;
		void    setRawBits(int const raw);
		
		int	 	toInt() const;
		float 	toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
