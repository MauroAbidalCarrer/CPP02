#ifndef FIXED_H
# define FIXED_H
# include <cmath>

class Fixed
{
    public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);

    private:
    static const int FRAC = 10;
    int rawBits;
};

#endif