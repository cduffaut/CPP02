#include "Fixed.hpp"

// Reste à faire : Dernier point de l'exercice
// Le reste normalement est correcte.

Fixed::Fixed() : _stock(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int convert)
{
    std::cout << "Int constructor called" << std::endl;
    _stock = convert << _bits;
}

// roundf is a cleaner way to cast you float into an integer
Fixed::Fixed(const float fconvert)
{
    std::cout << "Float constructor called" << std::endl;
    _stock = roundf(fconvert * (1 << _bits));
}

float   Fixed::toFloat() const
{
    return ((float)(_stock) / (1 << _bits));
}

// fix to float commas
// this->stock is the fixed commas representation that I want to convert
// 1 << this->bits is used ti moved the bits from this->bits pos to the left
// floatvalue allow us to pass from fixed to float value by divising by two the
// "entire" part (not after commas)
// the arg os just redirect the output of the func to the terminal
std::ostream    &operator<<(std::ostream &output, const Fixed &copy)
{
    output << copy.toFloat();
    return (output);
}

int     Fixed::toInt() const
{
    return (_stock >> _bits);
}

Fixed&  Fixed::operator=(const Fixed &copy2)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copy2)
        {
            _stock = copy2.getRawBits();
        }
        return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return (_stock);
}

void Fixed::setRawBits(int const raw)
{
    _stock = raw;
}