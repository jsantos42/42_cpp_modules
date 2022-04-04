#ifndef EX00_FIXED_H
#define EX00_FIXED_H

class Fixed {
public:
	/* ============= CONSTRUCTORS ============= */
	Fixed();
	Fixed(const Fixed& src);
	explicit Fixed(const int value);
	explicit Fixed(const float value);
	/* ============== DESTRUCTORS ============= */
	virtual ~Fixed();
	/* ========== OPERATOR OVERLOADS ========== */
	Fixed& operator=(const Fixed& rh_instance);

	int					getRawBits() const;
	void				setRawBits(const int raw);
	float				toFloat() const;
	int					toInt() const;
private:
	int					raw_bits;
	static const int	fractional_bits = 8;
};

/*
 * As stated in https://en.cppreference.com/w/cpp/language/operators, the
 * overloads of operator '>>' and '<<' that take std::istream& or std::os&
 * as the left hand argument (AKA insertion and extraction operators) must be
 * implemented as non-members, since they take the user-defined type as the
 * right hand argument.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif //EX00_FIXED_H
