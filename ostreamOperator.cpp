#include <iostream>


class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
	Fraction() : m_numerator(1), m_denominator(1) {}
	Fraction(int num, int den) : m_numerator(num), m_denominator(den) { }
	~Fraction() {}	

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fr) {
		os << "(" << fr.m_numerator << "," << fr.m_denominator << ")\n";
	   	return os;	
	} 

};

int main() {
	Fraction fr1(4,7);
	std::cout << "Fraction is " << fr1;

	return 0;
}

