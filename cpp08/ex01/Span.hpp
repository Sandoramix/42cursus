#ifndef SPAN_HPP
#define SPAN_HPP


class Span
{
private:
	unsigned int capacity;
public:
	Span(unsigned int N);
	Span(const Span &span);
	~Span();

	Span &operator=(const Span &span);

};


#endif //SPAN_HPP
