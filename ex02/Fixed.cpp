/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:00 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/03 21:54:28 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : m_n (0){
	// std::cout << "Default contructor called\n";
}

Fixed::Fixed(const int n) {
	this->m_n = n << this->m_bits;
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) {
	this->m_n = roundf(n * (1 << this->m_bits));
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructor called\n";
	*this = fixed;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called\n";
    return (this->m_n);
}

float	Fixed::toFloat(void) const {
	return ((float)(this->m_n / (float)(1 << this->m_bits)));
}

int	Fixed::toInt(void) const {
	return (this->m_n / (1 << this->m_bits));
}

Fixed&  Fixed::operator=(const Fixed& fixed){
	
	// std::cout << "Copy assignment operator called\n";
	this->m_n = fixed.m_n;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

Fixed&	Fixed::operator++(void){
	this->m_n++;
	return(*this);
}

//  local object will be destroyed when the function scope ends, leaving a dangling reference.
// For this reason whe don't return a reference, nor create a pointer for the object instantiated
// from the Fixed class

Fixed	Fixed::operator++(int){
	Fixed	copy(*this);
	this->m_n++;
	return(copy);
}

Fixed&	Fixed::operator--(void){
	this->m_n--;
	return(*this);
}

Fixed	Fixed::operator--(int){
	Fixed	copy(*this);
	this->m_n--;
	return(copy);
}

bool	Fixed::operator>(const Fixed& fixed){
	return (this->m_n > fixed.m_n);
}

bool	Fixed::operator<(const Fixed& fixed){
	return (this->m_n < fixed.m_n);
}

bool	Fixed::operator>=(const Fixed& fixed){
	return (this->m_n >= fixed.m_n);
}

bool	Fixed::operator<=(const Fixed& fixed){
	return (this->m_n <= fixed.m_n);
}

bool	Fixed::operator==(const Fixed& fixed){
	return (this->m_n == fixed.m_n);
}

bool	Fixed::operator!=(const Fixed& fixed){
	return (this->m_n != fixed.m_n);
}

// Fixed-Point Representation: In fixed-point representation, the position
// of the fractional part is fixed. When adding or subtracting, you're simply
// combining the integer representations, and the scale (i.e., position of the
// fractional part) remains unchanged.

Fixed	Fixed::operator+(const Fixed& fixed){
	Fixed	sum;

	sum = this->m_n + fixed.m_n;
	return (sum);
}

Fixed	Fixed::operator-(const Fixed& fixed){
	Fixed	subtraction;

	subtraction = this->m_n - fixed.m_n;
	return (subtraction);
}

// Multiplies the internal fixed-point representations and then 
// shifts right by m_bits to maintain the fixed-point scaling, because 
// if we just multiplied the m_n variables, we would be multiplying the int
// representations of the fixed-points, not actual fixed-points, hence the 
// result would be an int that doesn't correctly represent the fixed-points
// multiplication.

Fixed	Fixed::operator*(const Fixed& fixed){
	Fixed	multiplication;

	multiplication.m_n = (this->m_n * fixed.m_n) >> this->m_bits;
	return (multiplication);
}

// Shifts left by m_bits before dividing to maintain the fixed-point scaling.
// When dividing fixed-point numbers, the key challenge is maintaining precision.
// If you directly divide the scaled integers and then shift left, you could
// lose precision because integer division truncates the decimal part.

Fixed	Fixed::operator/(const Fixed& fixed){
	Fixed	division;

	division = this->m_n = (this->m_n << this->m_bits) / fixed.m_n;
	return (division);
}


Fixed&	Fixed::min(Fixed& leftfp, Fixed& rightfp){
	if (leftfp.getRawBits() > rightfp.getRawBits())
		return (rightfp);
	return (leftfp);
}

const Fixed&	Fixed::min(const Fixed& leftfp, const Fixed& rightfp){
	if (leftfp.getRawBits() > rightfp.getRawBits())
		return (rightfp);
	return (leftfp);
}

Fixed&	Fixed::max(Fixed& leftfp, Fixed& rightfp){
	if (leftfp.getRawBits() > rightfp.getRawBits())
		return (leftfp);
	return (rightfp);
}

const Fixed&	Fixed::max(const Fixed& leftfp, const Fixed& rightfp){
	if (leftfp.getRawBits() > rightfp.getRawBits())
		return (leftfp);
	return (rightfp);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called\n";
}

