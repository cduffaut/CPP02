#include "Fixed.hpp"

// Default Constructor that init value stock to 0
Fixed::Fixed() : stock(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// The copy constructor
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(copy.getRawBits());
}

// The affectation operator that upcharge 
Fixed&  Fixed::operator=(const Fixed& copy2)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &copy2)
        {
            stock = copy2.getRawBits();
        }
        return (*this);
}

// The destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Member function getRawBits
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (stock);
}

// Mumber function that init the commas number with the one in arg
void Fixed::setRawBits(int const raw)
{
    stock = raw;
}