#ifndef EX00_CONVERSIONS_H
#define EX00_CONVERSIONS_H

#include <iostream>
#include <string>

enum e_type {
	NAN,
	SPECIAL,
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
	void			storeStringNumber(const std::string& str);
	int				getType() const;
	double			getNumber() const;
	std::string 	getString() const;
	//==========================================================================
	// IS FUNCTIONS
	//==========================================================================
	bool			isSpecial(const std::string& str);
	bool			isChar(const std::string& str);
	bool			isInt(const std::string& str);
	bool			isFloat(const std::string& str);
	bool			isDouble(const std::string& str);
	//==========================================================================
	// PRINT FUNCTIONS
	//==========================================================================
	void			printChar() const;
	void			printInt() const;
	void			printFloat() const;
	void			printDouble() const;

private:
	Conversions();
	int			type;
	double		number;
	std::string	string;
};

#endif //EX00_CONVERSIONS_H
