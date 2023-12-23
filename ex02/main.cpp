#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    // display a
    std::cout << a << std::endl;
    // inc a then display it
    std::cout << ++a << std::endl;
    // display a
    std::cout << a << std::endl;
    // display a then inc it
    std::cout << a++ << std::endl;
    // display a
    std::cout << a << std::endl;
    // display b
    std::cout << b << std::endl;
    // compare and display the larger value between a and b
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}