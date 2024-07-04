/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/04 12:59:24 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include "Bsp.hpp"

#include <iostream>
#include <stdio.h>
int main( void ) {
	
	Point a(6.0f, 4.0f);
	Point b(16.0f, 4.0f);
	Point c(11.0f, 9.0f);
	Point p(19.0f, 1.0f);

	if (bsp(a, b, c, p) == true)
		std::cout << "Point is inside triangle\n";
	else
		std::cout << "Point is not inside triangle\n";
	return (0);

}