/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:57 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 18:09:34 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class   Fixed {
	public:
		Fixed();								// default constructor
		Fixed(const Fixed& fixed);  			// copy constructor
		Fixed(const int n);
		Fixed(const float f);       
		~Fixed();                   			// destructor


		Fixed&  operator=(const Fixed& fixed);	// copy assignement operator
		float   toFloat(void) const;
		int     toInt(void) const;
		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int                        _mn;
		static const int           _mbits = 8;
		

};

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
