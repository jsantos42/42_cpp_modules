#ifndef EX01_SPAN_H
#define EX01_SPAN_H

#include <vector>

class Span {
public:
	explicit Span(unsigned int N);
	Span(const Span &src);
	virtual ~Span();

	Span&			operator=(const Span &rh_instance);
	const std::vector<int>&	getVector() const;
	unsigned int			getMaxSize() const;

	template<typename T>
	void			addMultipleNumbers(typename T::const_iterator i, typename T::const_iterator ie);
	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

private:
	Span();
	std::vector<int>	v;
	unsigned int		max_size;
};

template<typename T>
void	Span::addMultipleNumbers(typename T::const_iterator i, typename T::const_iterator ie) {
	while (i < ie)
		addNumber(*(i++));
}


#endif //EX01_SPAN_H