/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:29:06 by crebelo-          #+#    #+#             */
/*   Updated: 2024/08/11 16:39:08 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

class   Fixed {
   
	public:
		Fixed(void);                            // default constructor
		Fixed(const Fixed& fixed);              // copy constructor
		~Fixed();                               // destructor

		Fixed&  operator=(const Fixed& fixed);  //copy assignement operator
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int                        _mn;
		static const int           _mbits = 8;

};

#endif
