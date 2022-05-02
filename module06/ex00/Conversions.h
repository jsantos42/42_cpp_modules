#ifndef EX00_CONVERSIONS_H
#define EX00_CONVERSIONS_H

#include <iostream>
#include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Conversions {
public:
	explicit Conversions(const std::string& str);
	Conversions(const Conversions &src);
	virtual ~Conversions();

	Conversions&	operator=(const Conversions &rh_instance);
	void			storeConversions(const std::string& str);
	int				getType(const std::string& str);
	char			getChar() const;
	int				getInt() const;
	float			getFloat() const;
	double			getDouble() const;

private:
	Conversions();
	int		type;
	char	c;
	int		i;
	float	f;
	double	d;
};

std::ostream&	operator<<(std::ostream os, const Conversions& obj);

#endif //EX00_CONVERSIONS_H
