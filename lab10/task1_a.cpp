#include <iostream>
#include <string>

class Vehicle
{
    int no_of_tires;
    char size;
    int no_of_seats;

public:
    Vehicle(int a = 0, int b = 0, char c = 0) : no_of_tires(a), size(c), no_of_seats(b) {}
    virtual void setValue()
    {
        std::cout << "Enter no of tires: ";
        std::cin >> no_of_tires;
        std::cout << "Enter no of seats: ";
        std::cin >> no_of_seats;
        std::cout << "Enter size of car as L,XL,S: ";
        std::cin >> size;
    }
    virtual void printValue() = 0;
    virtual int getTires()
    {
        return no_of_tires;
    }
    virtual char getSize()
    {
        return size;
    }
    virtual int getSeats()
    {
        return no_of_seats;
    }
};

class Car : public Vehicle
{
    std::string color;

public:
    Car(int a = 0, int b = 0, char c = ' ', std::string cl = " ") : Vehicle(a, b, c), color(cl){};
    void printValue()
    {
        std::cout << "\n--------Details---------\n";
        std::cout << "No. of tires are: " << Vehicle::getTires() << std::endl;
        std::cout << "No. of seats are: " << Vehicle::getSeats() << std::endl;
        std::cout << "The size of car : " << Vehicle::getSize() << std::endl;
        std::cout << "Color of car    : " << color << std::endl;
    }
    void setValue()
    {
        Vehicle::setValue();
        std::cout << "Enter the color of car: ";
        std::cin.ignore();
        getline(std::cin, color);
    }
    int getTires()
    {
        return Vehicle::getTires();
    }
    char getSize()
    {
        return Vehicle::getSize();
    }
    int getSeats()
    {
        return Vehicle::getSeats();
    }
};
class Vitz : public Car
{
    int model;
    int plate_number;

public:
    Vitz(int a = 0, int b = 0, char c = ' ', std::string cl = " ", int d = 0, int e = 0) : Car(a, b, c, cl), model(d), plate_number(e) {}
    void printValue()
    {
        Car::printValue();
        std::cout << "Model of car : " << model << std::endl;
        std::cout << "No. plate car: " << plate_number << std::endl;
    }
    void setValue()
    {
        Car::setValue();
        std::cout << "Enter the model of car: ";
        std::cin >> model;
        std::cout << "Enter the plate_number: ";
        std::cin >> plate_number;
    }

    int getTires()
    {
        return Car::getTires();
    }
    char getSize()
    {
        return Car::getSize();
    }
    int getSeats()
    {
        return Car::getSeats();
    }
    int getModel()
    {
        return model;
    }
    int getNoPlate()
    {
        return plate_number;
    }
};

int main()
{
    Vehicle *ptr;
    Car c;
    Vitz v;

    std::cout << "-------------------\n--------Car--------" << std::endl;
    ptr = &c;
    ptr->setValue();
    ptr->printValue();

    std::cout << "--------------------\n--------Vitz--------" << std::endl;
    ptr = NULL;
    ptr = &v;
    ptr->setValue();
    ptr->printValue();
    return 0;
}