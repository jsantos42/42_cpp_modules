#ifndef EX00_CONVERSIONS_H
#define EX00_CONVERSIONS_H

#include <iostream>
#include <string>

enum e_type {
	NAN,
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
	void			storeType(const std::string& str);
	int				getType() const;
	std::string 	getString() const;
	bool			isChar(const std::string& str);
	bool			isInt(const std::string& str);
	bool			isFloat(const std::string& str);
	bool			isDouble(const std::string& str);
	void			printChar() const;
	void			printInt() const;
	void			printFloat() const;
	void			printDouble() const;

private:
	Conversions();
	int			type;
	std::string	string;
};

#endif //EX00_CONVERSIONS_H
