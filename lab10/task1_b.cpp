#include <iostream>
#include <string>
using std::string;
class MyFather
{
    string name;
    string eye_color;
    string hair_color;

public:
    MyFather(string n = " ", string e = " ", string h = " ") : name(n), eye_color(e), hair_color(h) {}
    virtual void setter()
    {
        std::cout << "Enter name: ";
        getline(std::cin, name);
        std::cout << "Enter eye color: ";
        getline(std::cin, eye_color);
        std::cout << "Enter your hair color: ";
        getline(std::cin, hair_color);
    }
    virtual void print()
    {
        std::cout << "Name      : " << name << std::endl;
        std::cout << "Eye color : " << eye_color << std::endl;
        std::cout << "Hair color: " << hair_color << std::endl;
    }
    ~MyFather(){};
};
class MyMother
{
    string name;
    string eye_color;
    string hair_color;

public:
    MyMother(string a = " ", string b = " ", string c = " ") : name(a), eye_color(b), hair_color(c) {}
    virtual void setter()
    {
        std::cout << "Enter name: ";
        getline(std::cin, name);
        std::cout << "Enter eye color: ";
        getline(std::cin, eye_color);
        std::cout << "Enter your hair color: ";
        getline(std::cin, hair_color);
    }
    virtual void print()
    {
        std::cout << "Name      : " << name << std::endl;
        std::cout << "Eye color : " << eye_color << std::endl;
        std::cout << "Hair color: " << hair_color << std::endl;
    }
    ~MyMother() {}
};
class MySister : public MyFather, public MyMother
{
    string education;
    int age;

public:
    MySister(string a = " ", string b = " ", string c = " ", string d = " ", int e = 0) : MyFather(a, b, c), MyMother(a, b, c), education(d), age(e) {}
    void setter()
    {
        MyFather::setter();
        std::cout << "Enter your education: ";
        getline(std::cin, education);
        std::cout << "Enter your age: ";
        std::cin >> age;
        std::cin.ignore();
    }
    void print()
    {
        MyFather::print();
        std::cout << "Eduction: " << education << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
    ~MySister() {}
};
class MySelf : public MyFather
{
    string education;
    int age;

public:
    MySelf(string a = " ", string b = " ", string c = " ", string d = " ", int e = 0) : MyFather(a, b, c), education(d), age(e) {}
    void setter()
    {
        MyFather::setter();
        std::cout << "Enter your education: ";
        getline(std::cin, education);
        std::cout << "Enter your age: ";
        std::cin >> age;
        std::cin.ignore();
    }
    void print()
    {
        MyFather::print();
        std::cout << "Eduction: " << education << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
    ~MySelf() {}
};

int main()
{
    MyFather *fptr;
    MySister s;
    MySelf m;
    std::cout << "\n------MySelf-------\n";
    fptr = &m;
    fptr->setter();
    fptr->print();
    std::cout << "\n------Sister-------\n";
    fptr = NULL;
    fptr = &s;
    fptr->setter();
    fptr->print();
    return 0;
}