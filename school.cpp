#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string m_name, m_surname, m_status;

public:
    Person() : m_name("Unknow"), m_surname("Unknow"), m_status("Unknow") {}
    Person(string name, string surname, string status)
        : m_name(name), m_surname(surname), m_status(status) {}

    string getName() const { return m_name; }
    string getSurname() const { return m_surname; }
    string getStatus() const { return m_status; }

    virtual void goToHome() {}
    virtual void doSomething() {}
    virtual ~Person() {}
};

class Student : public Person {
private:
    string m_WhichClass;

public:
    Student() : Person("Unknow", "Unknow", "Unknow"), m_WhichClass("Unknow") {}

    Student(string name, string surname, string status, string WhClass="Unknow")
        : Person(name, surname, status), m_WhichClass(WhClass) {}

    void doHomework() {
        cout << "Do homework\n";
    }

    void doSomething() override {
        cout << "Go to school for study\n";
    }

    void goToHome() override {
        cout << "Go to home on a bus\n";
    }
};

class Teacher : public Person {
private:
    string m_specialist;
    int m_classRoom;

public:
    Teacher() : Person("Unknow", "Unknow", "Unknow"), m_specialist("Unknow"),m_classRoom(0) {}
        
    Teacher(string name, string surname, string status, string spec, int classRoom)
        : Person(name, surname, status), m_specialist(spec), m_classRoom(classRoom) {}

    void checkHomework() {
        cout << "Check homework\n";
    }

    void doSomething() override {
        cout << "Go to school for teach\n";
    }

    void goToHome() override {
        cout << "Go to home in a car\n";
    }
};
