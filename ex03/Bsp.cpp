/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:46:42 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/12 23:11:12 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <stdio.h>

Fixed calculate_area(Point const v1, Point const v2, Point const v3) {
	
	Fixed area1(v1.getPointX() * (v2.getPointY() - v3.getPointY()));
	Fixed area2(v2.getPointX() * (v3.getPointY() - v1.getPointY()));
	Fixed area3(v3.getPointX() * (v1.getPointY() - v2.getPointY()));


	Fixed area((area1 + area2 + area3).abs() / Fixed(2));
	
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	
	Fixed area1(calculate_area(a, b, point));
	Fixed area2(calculate_area(a, c, point));
	Fixed area3(calculate_area(c, b, point));
	Fixed areaAll(calculate_area(a, b, c));
	
	if ((area1 + area2 + area3) == areaAll)
		return (true);
	return (false);
   
}