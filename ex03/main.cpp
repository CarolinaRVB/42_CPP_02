/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/12 23:15:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include "Bsp.hpp"


int main( void ) {
	
	Point a(6.0f, 4.0f);
	Point b(16.0f, 4.0f);
	Point c(11.0f, 9.0f);
	Point p1(19.0f, 1.0f);
	Point p2(10.0f, 6.0f);
	

	if (bsp(a, b, c, p1) == true)
		std::cout << "Point is inside triangle\n";
	else
		std::cout << "Point is not inside triangle\n";

	if (bsp(a, b, c, p2) == true)
		std::cout << "Point is inside triangle\n";
	else
		std::cout << "Point is not inside triangle\n";
	return (0);

}