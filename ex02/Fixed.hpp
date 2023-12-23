#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class   Fixed
{
        public:
                // ex 00    
                Fixed();
                ~Fixed();
                // ex 01
                Fixed(const Fixed &copy);
                Fixed(int const convert);
                Fixed(float const fconvert);
                Fixed&              operator=(const Fixed &copy2);
                int                 getRawBits(void) const;
                void                setRawBits(int const raw);
                float               toFloat(void) const;
                int                 toInt(void) const;
                // ex 02
                bool               operator>(const Fixed &copy);
                bool               operator<(const Fixed &copy);
                bool               operator>=(const Fixed &copy);
                bool               operator<=(const Fixed &copy);
                bool               operator==(const Fixed &copy);
                bool               operator!=(const Fixed &copy);

                Fixed               operator+(const Fixed &copy);
                Fixed               operator-(const Fixed &copy);
                Fixed               operator*(const Fixed &copy);
                Fixed               operator/(const Fixed &copy);

                Fixed               operator++();
                Fixed               operator++(int);
                Fixed               operator--();
                Fixed               operator--(int);

                static Fixed            &min(Fixed &a, Fixed &b);
                static const Fixed      &min(const Fixed &a, const Fixed &b);

                static Fixed            &max(Fixed &a, Fixed &b);
                static const Fixed      &max(const Fixed &a, const Fixed &b);


         private:
                // ex 01
                int                 _stock;
                static const int    _bits = 8;
};

std::ostream       &operator<<(std::ostream &output, const  Fixed &copy);

#endif