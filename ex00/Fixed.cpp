/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:03 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/03 21:34:08 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// A fixed-point number is stored as an integer, but it represents a fraction.
// The position of the fractional part is fixed, and the scaling factor
// determines how the integer value should be interpreted as a fractional number. 

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
