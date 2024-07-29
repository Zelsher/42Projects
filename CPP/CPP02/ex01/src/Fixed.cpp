#include "../inc/Fixed.hpp"

Fixed::Fixed() : value(0) 
{
	cout << "Default constructor called" << endl; 
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value) 
{
	cout << "Copy constructor called" << endl;
}

Fixed::Fixed(const int value) : value(value << fractional_bits)
{}

Fixed::Fixed(const float value) : value((value * (1 << fractional_bits)))
{}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}