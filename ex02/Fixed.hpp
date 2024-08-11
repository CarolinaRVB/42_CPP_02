/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:57 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 18:44:15 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* const: When a member function is declared const, it means that the function 
 will not modify any member variables of the object on which it's called. 
 When a data member is const, it means its value cannot be changed after initialization.

// static const: This is typically used for constants that are shared among 
all instances of a class. static means the member is shared across all instances,
 and const means its value cannot be changed after initialization. For member functions, 
 static means the function can be called without an instance of the class and 
 can only access other static members.

Neither: If neither const nor static is used, the function or data member behaves
  normally, meaning it can modify the object's state, and each instance of the class 
  has its own copy of the member.
*/
#include <iostream>
#include <cmath>

class   Fixed {
	public:
		Fixed();					// default constructor
		Fixed(const Fixed& fixed);  // copy constructor
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();                   // destructor


		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);

		bool	operator>(const Fixed& fixed);
		bool	operator<(const Fixed& fixed);
		bool	operator>=(const Fixed& fixed);
		bool	operator<=(const Fixed& fixed);
		bool	operator==(const Fixed& fixed);
		bool	operator!=(const Fixed& fixed);
		Fixed&  operator=(const Fixed& fixed);

		Fixed	operator+(const Fixed& fixed);
		Fixed	operator-(const Fixed& fixed);
		Fixed	operator*(const Fixed& fixed);
		Fixed	operator/(const Fixed& fixed);
	
		static Fixed&	min(Fixed& leftfp, Fixed& rightfp);
		static const Fixed&	min(const Fixed& leftfp, const Fixed& rightfp);
		static Fixed&	max(Fixed& leftfp, Fixed& rightfp);
		static const Fixed&	max(const Fixed& leftfp, const Fixed& rightfp);
		

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

	private:
		int                        _mn;
		static const int           _mbits = 8;
		

};

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
