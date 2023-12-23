#include "Fixed.hpp"

// Reste à faire : Dernier point de l'exercice
// Le reste normalement est correcte.

Fixed::Fixed() : _stock(0){};

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::Fixed(const int convert)
{
    _stock = convert << _bits;
}

// roundf is a cleaner way to cast you float into an integer
Fixed::Fixed(const float fconvert)
{
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
        if (this != &copy2)
        {
            _stock = copy2.getRawBits();
        }
        return (*this);
}

Fixed::~Fixed(){};

int Fixed::getRawBits() const
{
    return (_stock);
}

void Fixed::setRawBits(int const raw)
{
    _stock = raw;
}

// ex02 funcs

bool    Fixed::operator>(const Fixed &copy)
{
    if (this->_stock > copy.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<(const Fixed &copy)
{
    if (this->_stock < copy.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed &copy)
{
    if (this->_stock >= copy.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator<=(const Fixed &copy)
{
    if (this->_stock <= copy.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator==(const Fixed &copy)
{
    if (this->_stock == copy.getRawBits())
        return (true);
    return (false);
}

bool    Fixed::operator!=(const Fixed &copy)
{
    if (this->_stock != copy.getRawBits())
        return (true);
    return (false);
}

Fixed   Fixed::operator+(const Fixed &copy)
{
    this->_stock += copy.getRawBits();
    return (_stock);
}

Fixed   Fixed::operator-(const Fixed &copy)
{
    this->_stock -= copy.getRawBits();
    return (_stock);   
}

Fixed   Fixed::operator*(const Fixed &copy)
{
    this->_stock = (this->toFloat() * copy.toFloat()) * (1 << this->_bits);
    return (*this);
}

Fixed   Fixed::operator/(const Fixed &copy)
{
    this->_stock = (this->toFloat() / copy.toFloat()) * (1 << this->_bits);
    return (*this);    
}

Fixed   Fixed::operator++()
{
    ++this->_stock;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed     tmp = (*this);
    ++this->_stock;
    return (tmp);
}

Fixed   Fixed::operator--()
{
    this->_stock++;
    return (_stock);
}

Fixed   Fixed::operator--(int)
{
    Fixed     tmp = (*this);
    --this->_stock;
    return (tmp);
}

Fixed           &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

Fixed const     &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

Fixed            &Fixed::max(Fixed &a, Fixed &b)
{
    if (a < b)
        return (b);
    return (a);
}

Fixed const     &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (b);
    return (a);
}