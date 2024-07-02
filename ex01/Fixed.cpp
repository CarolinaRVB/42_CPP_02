#include "Fixed.hpp"

Fixed::Fixed(const int n) : m_n (n) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called\n";
    *this = fixed;
}

Fixed::Fixed(const float n) {

}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

