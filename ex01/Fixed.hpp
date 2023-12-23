#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class   Fixed
{
    public:
            Fixed();
            Fixed(const Fixed &copy);
            Fixed(int const convert);
            Fixed(float const fconvert);
            ~Fixed();
            Fixed&              operator=(const Fixed &copy2);
            int                 getRawBits(void) const;
            void                setRawBits(int const raw);
            float               toFloat(void) const;
            int                 toInt(void) const;

    private:
            int                 _stock;
            static const int    _bits = 8;
};

std::ostream       &operator<<(std::ostream &output, const  Fixed &copy);

#endif