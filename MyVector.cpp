#include <iostream>
#include <vector>

class MyVector {
public:
   
    MyVector(unsigned int size, int value = 0): m_size(size), m_value(value), m_arr(new int[size]) {
		for(int i=0; i<m_size; i++){
			m_arr[i] = m_value;  
		}                                                               
	}
    
    //Copy constructor
    MyVector(const MyVector& other){
        std::cout << "call copy constructor\n";
        m_size=other.m_size;
        m_value=other.m_value;
       
        m_arr=new int[m_size];
        for(int i=0; i<m_size; i++){
            m_arr[i]=other.m_arr[i];
        }
    }

    ~MyVector(){
		delete[] m_arr;
		std::cout << "\nDestructor is called\n";
	};

    // Assignment operator
    MyVector& operator = (const MyVector& other){
        if(this != &other) {
            m_size = other.m_size;
            m_value = other.m_value;
            
            m_arr=new int[m_size];
            for(int i=0; i<m_size; i++){
                m_arr[i]=other.m_arr[i];
            }
        }
        return *this;
    }

    //resize
    void resize(unsigned int n) {
        int* newArr = new int[n];
        
        int limit = (n<m_size)? n : m_size;
        
        for(int i=0; i<limit; i++){
            newArr[i]=m_arr[i];
            if(i>=m_size){
                newArr[i]=0;
            }
        }
        delete[] m_arr;
        m_arr=newArr;
		m_size=n;
	}

    // Enables access to array elements using the [] operator, const element and non-const element.
    int& operator[](int index){
        return m_arr[index];
    }
    
    int operator[](int index) const{
        return m_arr[index];
    }

    //give size
    unsigned int size() const {
        return m_size;
    };

    //print vector
	void printMyVector() {
		for(int i=0; i<m_size; i++) {
			std::cout << m_arr[i] << " ";
		}
		std::cout << std::endl;
	}
	
private:
	int m_value;
    int* m_arr;
    unsigned int m_size;
};


int main(){
    //create object
	MyVector vec1{4, 2};
	MyVector vec2{5, 3};
	MyVector exe{3};
	exe.printMyVector();

    //call copy constructor
    MyVector vec3 = vec2;
    vec3.printMyVector();
	std::cout << std::endl;
    
	//resize
	std::cout << "resize\n";
	vec1.printMyVector();
	vec1.resize(7);
	vec1.printMyVector();
	vec1.resize(3);
	vec1.printMyVector();
	
	vec2.printMyVector();
	std::cout << std::endl;
	
	//return size
	std::cout << "return size\n";
    std::cout << vec1.size() << "\n";
	std::cout << vec2.size() << "\n";
	std::cout << std::endl;

	//elements
	std::cout << "elements\n";
    std::cout << vec1[2] << "\n";
    std::cout << vec2[2] << "\n";
    std::cout << (vec1[2]=4) << "\n";
    vec1.printMyVector();
    std::cout << (vec2[2]=5) << "\n";
    vec2.printMyVector();
	std::cout << std::endl;

    //Assignment op 
	std::cout << "Assignment op\n";
    vec1 = vec2;
    vec1.printMyVector();
	return 0;
}
