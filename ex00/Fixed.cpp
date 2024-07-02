#include "Fixed.hpp"

Fixed::Fixed(void) : m_n (0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called\n";
    *this = fixed;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

Fixed&  Fixed::operator=(const Fixed& fixed){
    
    std::cout << "Copy assignment operator called\n";
    this->m_n = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return (this->m_n);
}

void Fixed::setRawBits(int const raw) {
    this->m_n = raw;
}
