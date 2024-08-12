/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:00 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/12 21:57:03 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _mn (0){
	// std::cout << "Default contructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructor called\n";
	_mn = fixed._mn;
}

Fixed::Fixed(const int n) {
	_mn = n << _mbits;
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) {
	_mn = roundf(n * (1 << _mbits));
	// std::cout << "Float constructor called\n";
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called\n";
    return (_mn);
}

void Fixed::setRawBits(int const raw) {
	_mn = raw;
    // std::cout << "setRawBits member function called\n";
}

float	Fixed::toFloat(void) const {
	return ((float)(_mn / (float)(1 << _mbits)));
}

int	Fixed::toInt(void) const {
	return (_mn >> _mbits);
}

Fixed&  Fixed::operator=(const Fixed& fixed){
	
	if (this == &fixed) return *this;

	_mn = fixed._mn;
	// std::cout << "Copy assignment operator called\n";
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

Fixed&	Fixed::operator++(void){
	_mn++;
	return(*this);
}

//  local object will be destroyed when the function scope ends, leaving a dangling reference.
// For this reason whe don't return a reference, nor create a pointer for the object instantiated
// from the Fixed class

Fixed	Fixed::operator++(int){
	Fixed	copy(*this);
	_mn++;
	return(copy);
}

Fixed&	Fixed::operator--(void){
	_mn--;
	return(*this);
}

Fixed	Fixed::operator--(int){
	Fixed	copy(*this);
	_mn--;
	return(copy);
}

bool	Fixed::operator>(const Fixed& fixed) const{
	return (_mn > fixed._mn);
}

bool	Fixed::operator<(const Fixed& fixed) const{
	return (_mn < fixed._mn);
}

bool	Fixed::operator>=(const Fixed& fixed) const{
	return (_mn >= fixed._mn);
}

bool	Fixed::operator<=(const Fixed& fixed) const{
	return (_mn <= fixed._mn);
}

bool	Fixed::operator==(const Fixed& fixed) const{
	return (_mn == fixed._mn);
}

bool	Fixed::operator!=(const Fixed& fixed) const{
	return (_mn != fixed._mn);
}

// Fixed-Point Representation: In fixed-point representation, the position
// of the fractional part is fixed. When adding or subtracting, you're simply
// combining the integer representations, and the scale (i.e., position of the
// fractional part) remains unchanged.

Fixed	Fixed::operator+(const Fixed& fixed) const{
	Fixed	sum;

	sum._mn = _mn + fixed._mn;
	return (sum);
}

Fixed	Fixed::operator-(const Fixed& fixed) const{
	Fixed	subtraction;

	subtraction._mn =  _mn - fixed._mn;
	return (subtraction);
}

// Multiplies the internal fixed-point representations and then 
// shifts right by m_bits to maintain the fixed-point scaling, because 
// if we just multiplied the _mn variables, we would be multiplying the int
// representations of the fixed-points, not actual fixed-points, hence the 
// result would be an int that doesn't correctly represent the fixed-points
// multiplication.

Fixed	Fixed::operator*(const Fixed& fixed) const{
	Fixed	multiplication;

	multiplication._mn = (_mn * fixed._mn) >> _mbits;
	return (multiplication);
}

// Shifts left by m_bits before dividing to maintain the fixed-point scaling.
// When dividing fixed-point numbers, the key challenge is maintaining precision.
// If you directly divide the scaled integers and then shift left, you could
// lose precision because integer division truncates the decimal part.

Fixed	Fixed::operator/(const Fixed& fixed) const{

	if (fixed._mn == 0){
		std::cout << "Error: can't divide by zero\n";
		return (*this);
	}
	return (Fixed(toFloat() / fixed.toFloat()));
}


Fixed&	Fixed::min(Fixed& leftfp, Fixed& rightfp){
	if (leftfp._mn > rightfp._mn)
		return (rightfp);
	return (leftfp);
}

const Fixed&	Fixed::min(const Fixed& leftfp, const Fixed& rightfp){
	if (leftfp._mn > rightfp._mn)
		return (rightfp);
	return (leftfp);
}

Fixed&	Fixed::max(Fixed& leftfp, Fixed& rightfp){
	if (leftfp._mn > rightfp._mn)
		return (leftfp);
	return (rightfp);
}

const Fixed&	Fixed::max(const Fixed& leftfp, const Fixed& rightfp){
	if (leftfp._mn > rightfp._mn)
		return (leftfp);
	return (rightfp);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called\n";
}

