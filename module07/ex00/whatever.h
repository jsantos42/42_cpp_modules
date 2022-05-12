#ifndef EX00_WHATEVER_H
#define EX00_WHATEVER_H

template<typename A>
void	swap(A& a1, A& a2) {
	A	tmp;

	tmp = a1;
	a1 = a2;
	a2 = tmp;
}

template<typename B>
const B&	min(const B& b1, const B& b2) {
	return (b1 < b2 ? b1 : b2);
}

template<typename C>
const C&	max(const C& c1, const C& c2) {
	return (c1 > c2 ? c1 : c2);
}

#endif //EX00_WHATEVER_H
