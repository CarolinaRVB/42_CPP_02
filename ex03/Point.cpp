/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:10:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/04 12:20:57 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : m_x (0), m_y (0) {
	
}

Point::Point(const float a, const float b) : m_x (a), m_y (b) {

}

Point::Point(const Point& point){
	*this = point;
}

Point::~Point(){
	
}

// all members of the Point class are const, meaning we cannot assign anything to them 
// hence cannot do a copy, we only return the object itself
Point&	Point::operator=(const Point& point) {
	if (this == &point)
		return (*this);
	return (*this);
}

Fixed    Point::getPointX(void) const {
	return (this->m_x);
}

Fixed    Point::getPointY(void) const {
	return (this->m_y);
}