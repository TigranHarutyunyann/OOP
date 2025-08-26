#include <iostream>


class Animal {
public:
   void eat() { std::cout << "eat\n"; }
   virtual ~Animal() {}
};

class Dog : public Animal {
public:
  void Bark() {std::cout << "bark\n";}
  ~Dog() {}
};

void BarkIfPossible(Animal* animal) {
	Dog* d = dynamic_cast<Dog*>(animal);
	if(d){
		d->Bark();
	}else {
		std::cout << "Casting failed\n";
	}
}

int main() {

	Animal* an = new Dog;
	BarkIfPossible(an);
    delete an;

	Animal* na = new Animal;
	BarkIfPossible(na);
	delete na;


	return 0;
}
