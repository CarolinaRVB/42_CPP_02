/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:03 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 16:56:23 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// A fixed-point number is stored as an integer, but it represents a fraction.
// The position of the fractional part is fixed, and the scaling factor
// determines how the integer value should be interpreted as a fractional number. 

Fixed::Fixed(void) : _mn (0) {
	std::cout << "Default constructor called\n";
}

/* 
	Copy constructor, could've used *this = fixed which would've called the
	copy assignement operator function
*/
Fixed::Fixed(const Fixed& fixed) {
	
	_mn = fixed._mn;
	
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed&  Fixed::operator=(const Fixed& fixed){
	
	if (this == &fixed) return *this;
	
	_mn = fixed._mn;
	
	std::cout << "Copy assignment operator called\n";
	
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_mn);
}

void Fixed::setRawBits(int const raw) {
	_mn = raw;
}
