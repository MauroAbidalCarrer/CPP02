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
Fixed const	&Fixed::min(Fixed const &n1, Fixed const &n2)
{
	return (n1.rawBits < n2.rawBits ? n1 : n2);
}

Fixed const	&Fixed::max(Fixed const &n1, Fixed const &n2)
{
	return (n1.rawBits > n2.rawBits ? n1 : n2);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	return (n1.rawBits < n2.rawBits ? n1 : n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	return (n1.rawBits > n2.rawBits ? n1 : n2);
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
bool	Fixed::operator>(Fixed const &rhs) const
{
	return (rawBits > rhs.rawBits);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (rawBits < rhs.rawBits);	
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (rawBits >= rhs.rawBits);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (rawBits <= rhs.rawBits);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (rawBits == rhs.rawBits);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (rawBits != rhs.rawBits);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	Fixed res;
	res.setRawBits(rawBits + rhs.rawBits);
	return (res);
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	Fixed res;
	res.setRawBits(rawBits - rhs.rawBits);
	return (res);
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	Fixed res;
	res.setRawBits(rawBits * rhs.rawBits / (1 << FRAC));
	return (res);
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	Fixed res;
	res.setRawBits(rawBits / rhs.rawBits * (1 << FRAC));
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed res(*this);
	rawBits++;
	return (res);
}

Fixed	&Fixed::operator--(void)
{
	rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed res(*this);
	rawBits--;
	return (res);
}
//other
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}