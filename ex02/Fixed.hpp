#ifndef FIXED_H
# define FIXED_H
# include <cmath>
# include <iostream>

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
    static Fixed const	&min(Fixed const &n1, Fixed const &n2);
    static Fixed const	&max(Fixed const &n1, Fixed const &n2);
    static Fixed	&min(Fixed &n1, Fixed &n2);
    static Fixed	&max(Fixed &n1, Fixed &n2);

    //overloads
    Fixed& operator=(Fixed const &rhs);
    bool operator>(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;
    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    ~Fixed();

    private:
    static const int FRAC;
    int rawBits;
};
std::ostream &operator<<(std::ostream &output, Fixed const &rhs);
#endif