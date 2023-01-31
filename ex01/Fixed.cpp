#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const	Fixed::FRAC = 8;

//constructors
Fixed::Fixed()
{
    rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = integer * (1 << FRAC);
}
Fixed::Fixed(const float floating)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(floating * (1 << FRAC));
}
//methods
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called " << std::endl;
    return rawBits;
}
void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}
float Fixed::toFloat() const
{
    return ((float)(rawBits) / (1 << FRAC));
}
int Fixed::toInt() const
{
    return rawBits / (1 << FRAC);
}
//overloads
std::ostream &operator<<(std::ostream &output, Fixed const &rhs)
{
	output << rhs.toFloat();
	return (output);
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    rawBits = other.rawBits;
    return *this;
}
//other
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}