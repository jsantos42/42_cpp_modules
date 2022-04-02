#ifndef EX00_FIXED_H
#define EX00_FIXED_H


class Fixed {
public:
	Fixed();                        // Default constructor
	Fixed(const Fixed &src);    	// Copy constructor
	virtual ~Fixed();               // Default destructor
	Fixed &operator=(const Fixed &rh_instance);    // Assign operator overload

	int					getRawBits() const;
	void				setRawBits(const int raw);

private:
	int					fixed_point_number;
	static const int	fractional = 8;
};


#endif //EX00_FIXED_H
