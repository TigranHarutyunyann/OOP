#include <iostream>

int gcd(int a, int b){
	if(a==b) {return a;}
	if(a<b) {
		int tmp = a;
		a=b;
		b=tmp;
		return gcd(b, a-b);
	}else{
		return gcd(b, a-b);
	} 
}


class Fraction {
private:
    int m_numerator; 
    int m_denominator;

public:
    //default const and Constructor with two parameters
    Fraction(int numer=1, int denom=1) : m_numerator(numer), m_denominator(denom) { }
    
    //3.+,  -,  *,  / operators to perform arithmetic between two fractions.
    
    //+
    Fraction operator+(const Fraction& other) const {
        return Fraction(m_numerator+other.m_numerator, m_denominator+other.m_denominator);
    }
    
    //-
    Fraction operator-(const Fraction& other) const {
        return Fraction(m_numerator-other.m_numerator, m_denominator-other.m_denominator);	
    }
    
	//*
    Fraction operator*(const Fraction& other) const {
        return Fraction(m_numerator*other.m_numerator, m_denominator*other.m_denominator);	
    }
    
    // '/
    Fraction operator/(const Fraction& other) const {
        return Fraction(m_numerator/other.m_numerator, m_denominator/other.m_denominator);	
    }
    
	//4. <, >, == and != for comparison.
    
    //<
    bool operator<(const Fraction& other) const {
        return m_numerator*other.m_denominator < other.m_numerator*m_denominator; 
    }
    
    //>
    bool operator>(const Fraction& other) const {
        return m_numerator*other.m_denominator > other.m_numerator*m_denominator; 
    }
    
    //==
    bool operator==(const Fraction& other) const {
        return m_numerator*other.m_denominator == other.m_numerator*m_denominator; 
    }
    
    //!=
    bool operator!=(const Fraction& other) const {
        return m_numerator*other.m_denominator != other.m_numerator*m_denominator; 
    }    
    
	// 5. A simplify() method that reduces the fraction to its lowest terms.
    Fraction simplify() {
		 int number = gcd(m_numerator, m_denominator);
		 return Fraction( m_numerator/=number, m_denominator/=number );
	}

	//6. A toDouble() method that returns the decimal value.
	void toDouble() {
		double m_num_double=static_cast<double>(m_numerator);
		double m_den_double=static_cast<double>(m_denominator);
		double result =  m_num_double/m_den_double;
		std::cout << result << std::endl;
	}

    //print               
    void print(){
        std::cout <<"("<< m_numerator <<"/"<<m_denominator<<")";  
    }
};



int main() {
    Fraction f1(3,4);
    Fraction f2(1,2);
	std::cout << "f1 is "; f1.print();
    std::cout << "\nf2 is "; f2.print();
    
    Fraction f3 = f1 + f2;
	std::cout << "\nf1 + f2 = f3 = "; f3.print();
	Fraction f4 = f1 - f2;
	std::cout << "\nf1 - f2 = f4 = "; f4.print();
	Fraction f5 = f1 * f2;
	std::cout << "\nf1 * f2 = f5 = "; f5.print();
	Fraction f6 = f1 / f2;
	std::cout << "\nf1 / f2 = f6 = "; f6.print();
    
	bool a1 = f3 < f4;
	bool a2 = f5 > f6;
	bool a3 = f1 == f2;
	bool a4 = f3 != f5;
	std::cout << std::boolalpha;
	std::cout << "\nf3 < f4 is " << a1 << std::endl;
	std::cout << "f5 > f6 is " << a2 << std::endl;
	std::cout << "f1 == f2 is " << a3 << std::endl;
	std::cout << "f3 != f5 is " << a4 << std::endl;

	std::cout << "Simplify franction of "; f3.print(); std::cout << " is "; f3.simplify(); f3.print(); std::cout << std::endl;

	std::cout << "The result of "; f1.print(); std::cout << " is "; f1.toDouble(); 
	std::cout << "The result of "; f2.print(); std::cout << " is "; f2.toDouble(); 
	std::cout << "The result of "; f3.print(); std::cout << " is "; f3.toDouble(); 
	return 0;
}
