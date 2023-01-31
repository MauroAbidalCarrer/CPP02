#ifndef FIXED_H
# define FIXED_H
# include <cmath>

class Fixed
{
    public:
    //constructors
    Fixed();
    Fixed(const Fixed& other);
    //methods
    int getRawBits() const;
    void setRawBits(int const raw);
    //others
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    private:
    static const int FRAC = 10;
    int rawBits;
};

#endif