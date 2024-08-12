/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:10:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/12 22:50:03 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _mx (0), _my (0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float a, const float b) : _mx (a), _my (b) {
	// std::cout << "Constructor called" << std::endl;
}

/*
	Since _mx and _my are const Fixed objects, the only way to initialize
	them in the Point class copy constructor, is to use a constructor 
	initialization list because they must be set at the time of construction.
*/
Point::Point(const Point& point) : _mx(point._mx), _my(point._my) {
	// std::cout << "Copy constructor called" << std::endl;	
}

Point::~Point(){
	// std::cout << "Destructor called" << std::endl;
}

// all members of the Point class are const, meaning we cannot assign anything to them 
// hence cannot do a copy, we only return the object itself
Point&	Point::operator=(const Point& point) {
	if (this == &point) return (*this);
	return (*this);
}

Fixed    Point::getPointX(void) const {
	return (_mx);
}

Fixed    Point::getPointY(void) const {
	return (_my);
}