#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class   Fixed
{
    public:
            Fixed();
            Fixed(const Fixed& copy);
            ~Fixed();
            Fixed& operator=(const Fixed& copy2);
            int getRawBits(void) const;
            void setRawBits(int const raw);

    private:
            int                 stock;
            static const int    bits = 8;
};

#endif