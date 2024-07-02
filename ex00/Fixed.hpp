#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>

class   Fixed {
    public:
        Fixed(void);                // default constructor
        Fixed(const Fixed& fixed);  // copy constructor
        ~Fixed();                   // destructor

        Fixed&  operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int                        m_n;
        const static int           m_bits = 8;
        

};

#endif
