#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

using namespace std;

class Fixed
{
	private:
		int					value;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		int		getRawBits(void) const { return value; };
		void	setRawBits(const int raw) { value = raw; };
};

#endif