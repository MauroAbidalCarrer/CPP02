#include "Fixed.hpp"
#include <iostream>

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

//others
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called " << std::endl;
    setRawBits(other.getRawBits());
    return *this;
}
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}