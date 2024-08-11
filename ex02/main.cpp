/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:52 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 19:31:19 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
    std::cout << a << std::endl;                  // Default value of a (should be 0)
    std::cout << ++a << std::endl;                
    std::cout << a << std::endl;                  
    std::cout << a++ << std::endl;                
    std::cout << a << std::endl;                  

    std::cout << b << std::endl;                  // Value of b (should be 10.10)

    // Instance vs. Class Context: Non-static member functions require an instance
    // to be called, while static member functions do not.

    std::cout << Fixed::max(a, b) << std::endl;   // Maximum of a and b (should be 10.10)

	std::cout << "\n\n##################################\n";
	std::cout << "#           More tests           #\n";    
	std::cout << "##################################\n\n";
	
	
    // Additional operations

    Fixed c(10);
    Fixed d(2);
    std::cout << "c: " << c << std::endl;        // Value of c (should be 10)
    std::cout << "d: " << d << std::endl;        // Value of d (should be 2)
    
    std::cout << "c + d: " << (c + d) << std::endl; // c + d (should be 12)
    std::cout << "c - d: " << (c - d) << std::endl; // c - d (should be 8)
    std::cout << "c * d: " << (c * d) << std::endl; // c * d (should be 20)
    std::cout << "c / d: " << (c / d) << std::endl; // c / d (should be 5)
	std::cout << std::endl;
	
    // Testing comparison operations
    std::cout << "c > d: " << (c > d) << std::endl;  // True (1) because 10 > 2
    std::cout << "c < d: " << (c < d) << std::endl;  // False (0) because 10 < 2 is false
    std::cout << "c >= d: " << (c >= d) << std::endl; // True (1) because 10 >= 2
    std::cout << "c <= d: " << (c <= d) << std::endl; // False (0) because 10 <= 2 is false
    std::cout << "c == d: " << (c == d) << std::endl; // False (0) because 10 == 2 is false
    std::cout << "c != d: " << (c != d) << std::endl; // True (1) because 10 != 2
	std::cout << std::endl;

    // Testing increment and decrement operators
    std::cout << "Initial c: " << c << std::endl;    // Initial value of c (should be 10)
    std::cout << "c++: " << c++ << std::endl;        
    std::cout << "After c++: " << c << std::endl;    
    std::cout << "++c: " << ++c << std::endl;        
    std::cout << "c--: " << c-- << std::endl;        
    std::cout << "After c--: " << c << std::endl;    
    std::cout << "--c: " << --c << std::endl; 
	std::cout << std::endl;

    // Testing min and max functions
    Fixed e(3);
    Fixed f(7);
    std::cout << "e: " << e << std::endl;           // Value of e (should be 3)
    std::cout << "f: " << f << std::endl;           // Value of f (should be 7)
    std::cout << "Min(e, f): " << Fixed::min(e, f) << std::endl; // Minimum of e and f (should be 3)
    std::cout << "Max(e, f): " << Fixed::max(e, f) << std::endl; // Maximum of e and f (should be 7)


	return 0;
}