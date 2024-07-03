/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:57 by crebelo-          #+#    #+#             */
/*   Updated: 2024/07/03 17:41:45 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class   Fixed {
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);       // default constructor
		Fixed(const Fixed& fixed);  // copy constructor
		~Fixed();                   // destructor


		Fixed&  operator=(const Fixed& fixed);
		float   toFloat(void) const;
		int     toInt(void) const;

	private:
		int                        m_n;
		const static int           m_bits = 8;
		

};

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
