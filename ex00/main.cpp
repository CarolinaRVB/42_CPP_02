/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:09 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 16:52:05 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;


	std::cout << "\n\n##################################\n";
	std::cout << "#           More tests           #\n";    
	std::cout << "##################################\n\n";
	

	b.setRawBits(42);
	a = b;
	std::cout << "\nRaw bits of B after setRawBits with 42: " << b.getRawBits() << std::endl;
    std::cout << "\nRaw bits of C who is a copy of b but should maintain the value 0 since it was copied before the setting of 42: " << c.getRawBits() << std::endl;
	std::cout << "\nRaw bits of A, should be 42: " <<  a.getRawBits() << std::endl;
	
	
	return 0;
}