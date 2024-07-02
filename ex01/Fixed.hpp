#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class   Fixed {
    public:
        Fixed(const int n);
        Fixed(const float f);                // default constructor
        Fixed(const Fixed& fixed);  // copy constructor
        ~Fixed();                   // destructor


        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int                        m_n;
        const static int           m_bits = 8;
        

};

#endif
