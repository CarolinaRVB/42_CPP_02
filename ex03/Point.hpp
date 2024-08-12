/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:10:09 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/12 22:23:31 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
	public:
		Point(void);
		Point(const float a, const float b);
		Point(const Point& point);

		Point&	operator=(const Point& point);
		
		Fixed	getPointX(void) const;
		Fixed	getPointY(void) const;
	
		~Point();
		
	private:
		Fixed const _mx;
		Fixed const _my;
	
};


#endif
