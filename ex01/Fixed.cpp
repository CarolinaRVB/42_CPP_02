/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:00 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/03 17:41:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
	std::cout << "Default contructor called\n";
}

Fixed::Fixed(const int n) {
	this->m_n = n << this->m_bits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) {
	this->m_n = roundf(n * (1 << this->m_bits));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed&  Fixed::operator=(const Fixed& fixed){
    
    std::cout << "Copy assignment operator called\n";
    this->m_n = fixed.m_n;
    return *this;
}

float	Fixed::toFloat(void) const {
	return ((float)(this->m_n / (float)(1 << this->m_bits)));
}

int	Fixed::toInt(void) const {
	return (this->m_n / (1 << this->m_bits));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

