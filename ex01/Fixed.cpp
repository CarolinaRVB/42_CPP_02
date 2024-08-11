/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:00 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 18:38:13 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _mn(0) {
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
	
	_mn = fixed._mn;
	
	std::cout << "Copy constructor called\n";
}

/*
	Constructor that converts an int to a fixed-point value.
	
	How?
	By shifting the bits to the left according to the number of fractional bits
	defined. Which is the same as multiplying the number by 2^(fractional bits), which
	will be equal to n * 256 (2^8 = 256)
	Since the fractional bits are initialized to 8, we shift all the bits on the
	int 8 positions to the left
*/
Fixed::Fixed(const int n) {
	_mn = n << _mbits;
	std::cout << "Int constructor called\n";
}

/*
	Constructor that converts a float to a fixed-point value.
	
	How?
	In this case, we can't bit shift n fractional bits because bit shifting is not allowed
	in floating point numbers. Hence we work around it.
	For this we can scale the float value to fit into the fixed-point representation and then 
	round it.
	To scale it we multiply the float by 2^fractionalBits, which scales the float to 
	an integer that represents the fixed-point format.
	Then round the final value to convert it to integer

	1 : 00000001
		1 << _mbits( = 8)
	1: 10000000 = 256
*/
Fixed::Fixed(const float n) {
	_mn = roundf(n * (1 << _mbits));
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed&  Fixed::operator=(const Fixed& fixed){
	
	if (this == &fixed) return *this;
	
	std::cout << "Copy assignment operator called\n";
	
	_mn = fixed._mn;
	
	return *this;
}

/*
	Function that converts a fixed-point to a float value.
	
	How?
	To the equation the other way around
	Need to cast float because we're dividing integers
*/
float	Fixed::toFloat(void) const {
	return ((float)(_mn / (float)(1 << _mbits)));
}

/*
	Function that converts a fixed-point to an int value.
	
	How?
	To the equation the other way around
*/
int	Fixed::toInt(void) const {
	return (_mn >> _mbits);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_mn);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_mn = raw;
}

/*
	Operator overloader
	
	This is required because std::cout is only able to handle basic types
	like int, float, char, char*, double etcm not fixed-point values
*/
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}
