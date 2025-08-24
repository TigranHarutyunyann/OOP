#include <iostream>
#include <vector>
                          
template <typename T>
class MyVector {
private:
	T m_value;
	T* m_arr;
	unsigned int m_size;

public:
    MyVector() : m_size(1), m_value(0), m_arr(new T[1]) {
		m_arr[0]=m_value;
	}

	MyVector(unsigned int size, T value=0)  
	    : m_size(size), m_value(value), m_arr(new T[size]) {
		for(int i=0; i<m_size; i++) {
			m_arr[i] = m_value;
		}
	}

	//Copy constructor
	MyVector(const MyVector& other) {
		std::cout << "call copy constructor\n";
		m_size=other.m_size;
		m_value=other.m_value;

		m_arr=new T[m_size];
		for(int i=0; i<m_size; i++) {
			m_arr[i]=other.m_arr[i];
		}
	}

	~MyVector() {
		delete[] m_arr;
	}

	// Assignment operator
	MyVector& operator = (const MyVector& other) {
		if(this != &other) {
			delete[] m_arr;
			m_size = other.m_size;
			m_value = other.m_value;
			m_arr=new T[m_size];
			for(int i=0; i<m_size; i++) {
				m_arr[i]=other.m_arr[i];
			}
		}
		return *this;
	}

	//resize
	void resize(unsigned int n) {
		T* newArr = new T[n];

		int limit = (n<m_size)? n : m_size;

		for (int i = 0; i < limit; i++) {
            newArr[i] = m_arr[i];
        }
        for (int i = limit; i < n; i++) {
            newArr[i] = 0;
        }
        
		delete[] m_arr;
		m_arr=newArr;
		m_size=n;
	}

	// []
	int& operator[](int index) {
		return m_arr[index];
	}
	int operator[](int index) const {
		return m_arr[index];
	}

	//give size
	unsigned int size() const {
		return m_size;
	}

	//reserve
	void reserve() {
		T* newArr = new T[m_size];

		for(int i=m_size-1; i>=0; i--) {
			newArr[m_size-i-1]=m_arr[i];
		}
		delete[] m_arr;
		m_arr = newArr;
	}

	//capacity
	int capacity(){
		std::vector<T> vecNew;
		for(int i=0; i<m_size; i++) {
			vecNew.push_back(m_arr[i]);
		}	
		return vecNew.capacity();
	}

	//push_back declaration
	void push_back(const T& value);
	
	//pop_back declaration
	void pop_back();

	//print vector
	void print() {
		for(int i=0; i<m_size; i++) {
			std::cout << m_arr[i] << " ";
		}
		std::cout << std::endl;
	}

};

//push_back definition
template <typename T> 
void MyVector<T>::push_back(const T& value){
	std::vector<T> newVec;
	for(int i=0; i<m_size; i++) {
		newVec.push_back(m_arr[i]);	
	}	
	newVec.push_back(value);
	m_size += 1;
	T* new_arr = new T[m_size];
	for(int i = 0; i<m_size; i++) {
		new_arr[i] = newVec[i];  
	}
	delete[] m_arr;
	m_arr = new_arr;
}

//pop_back definition 
template <typename T> 
void MyVector<T>::pop_back( ){
	std::vector<T> newVec;
	for(int i=0; i<m_size; i++) {
		newVec.push_back(m_arr[i]);	
	}	
	newVec.pop_back();
	m_size -= 1;
	T* new_arr = new T[m_size];
	for(int i = 0; i<m_size; i++) {
		new_arr[i] = newVec[i];  
	}
	delete[] m_arr;
	m_arr = new_arr;
}


int main() {

	//create object
	MyVector<int> vec1{4, 2};
	MyVector<double> db{10, 5.5};
    db.print();

	//call copy constructor
	MyVector<int> vec2 = vec1;
	vec2.print();
	std::cout << std::endl;

	//resize
	std::cout << "resize\n";
	vec1.print();
	vec1.resize(7);
	vec1.print();

	//return size
	std::cout << "return size\n";
	std::cout << vec1.size() << "\n";
	std::cout << std::endl;

	//elements
	std::cout << "elements\n";
	std::cout << vec1[2] << "\n";
	vec1.print();
	std::cout << (vec1[2]=4) << "\n";
	vec1[1]=111;
	vec1.print();

	//reserve
	std::cout << "\nreserve\n";
    vec1.reserve();
	vec1.print();        

	//capacity
	std::cout << "\ncapacity is " << vec1.capacity();
	std::cout << "\ncapacity is " << db.capacity();
                            
	//Assignment op
	std::cout << "\nAssignment op\n";
	vec1 = vec2;
	vec1.print();
	std::cout << std::endl;

    //push_back
	std::cout << "\npush_back\n";
	vec1.push_back(9999);
	vec1.print();

    //pop_back
	std::cout << "\npop_back\n";
	vec1.pop_back();
	vec1.print();

	return 0;
}
