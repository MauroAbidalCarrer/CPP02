#ifndef FIXED_H
# define FIXED_H
# include <cmath>
#include <iostream>

class Fixed
{
    public:
    //constructor
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int integer);
    Fixed(const float floating);
    //methods
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
    //overloads
    Fixed& operator=(Fixed const &rhs);

    ~Fixed();

    private:
    static const int FRAC;
    int rawBits;
};
std::ostream &operator<<(std::ostream &output, Fixed const &rhs);
#endif