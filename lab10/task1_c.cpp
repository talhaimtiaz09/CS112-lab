#include <iostream>
#include <string>
#include <math.h>

using std::string;

class Shape
{
    float length;
    float width;

public:
    Shape(float l = 0, float w = 0) : length(l), width(w) {}
    virtual float area() = 0;
    virtual float volume()
    {
        return 0.0;
    }
    virtual void setter()
    {
        std::cout << "Please enter length: ";
        std::cin >> length;
        std::cout << "Please enter width: ";
        std::cin >> width;
    }

    virtual float getLength()
    {
        return length;
    }
    virtual float getWidth()
    {
        return width;
    }
    virtual string getColor() { return " "; }

    ~Shape() {}
};
class Shapes2D : public Shape
{
public:
    Shapes2D(float l = 0, float w = 0) : Shape(l, w) {}
    float area() = 0;
    void setter()
    {
        Shape::setter();
    }
    float getLength()
    {
        return Shape::getLength();
    }
    float getWidth()
    {
        return Shape::getWidth();
    }
    ~Shapes2D() {}
};

class Circle : public Shapes2D
{
    float radius;
    string color;

public:
    Circle(float r = 0, string c = " ") : radius(r), color(c) {}
    void setter()
    {
        std::cout << "Please enter radius: ";
        std::cin >> radius;
        std::cout << "Please enter the color: ";
        std::cin.ignore();
        std::getline(std::cin, color);
    }
    string getColor()
    {
        return color;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
    ~Circle() {}
};
class Square : public Shapes2D
{
    float side;
    string color;

public:
    Square(float s = 0, string c = " ") : side(s), color(c) {}

    void setter()
    {
        std::cout << "Please the length of side: ";
        std::cin >> side;
        std::cout << "Please enter the color: ";
        std::cin.ignore();
        std::getline(std::cin, color);
    }
    float area()
    {
        return side * side;
    }
    string getColor()
    {
        return color;
    }
    float getSide()
    {
        return side;
    }

    ~Square() {}
};

class Shapes3D : public Shape
{

public:
    Shapes3D(float l = 0, float w = 0) : Shape(l, w) {}
    float area() = 0;
    void setter()
    {
        Shape::setter();
    }
    virtual float volume() = 0;
    float getLength()
    {
        return Shape::getLength();
    }
    float getWidth()
    {
        return Shape::getWidth();
    }

    ~Shapes3D() {}
};

class Cube : public Shapes3D
{
    float height;

public:
    Cube(float l = 0, float w = 0, float h = 0) : Shapes3D(l, w), height(h) {}
    float area()
    {
        float length = this->getLength();
        float width = this->getWidth();
        return (2 * length * width) + (2 * length * height) + (2 * height * width);
    }
    float volume()
    {
        return this->getLength() * this->getWidth() * height;
    }
    void setter()
    {
        Shapes3D::setter();
        std::cout << "Please enter height: ";
        std::cin >> this->height;
    }
    float getLength()
    {
        return Shape::getLength();
    }
    float getWidth()
    {
        return Shape::getWidth();
    }
    float getHeight()
    {
        return height;
    }
    ~Cube() {}
};
class Pyramid : public Shapes3D
{
    float base;
    float height;

public:
    Pyramid(float l = 0, float w = 0, float h = 0) : Shapes3D(l, w), height(h), base(l * w) {}
    float volume()
    {
        float l = this->getLength();
        float w = this->getWidth();
        return l * w * height / 3.0;
    }
    float area()
    {
        float l = this->getLength();
        float w = this->getWidth();
        float h = this->height;
        return l * w + l * sqrt(pow(w / 2, 2) + pow(h, 2)) + w * sqrt(pow(l / 2, 2) + pow(h, 2));
    }
    void setter()
    {
        Shapes3D::setter();
        std::cout << "Please enter height: ";
        std::cin >> this->height;
    }
    float getLength()
    {
        return Shape::getLength();
    }
    float getWidth()
    {
        return Shape::getWidth();
    }
    float getHeight()
    {
        return height;
    }
};
int main()
{
    Shape *ptr;
    //******Pyramid********
    Pyramid py;
    ptr = NULL;
    ptr = &py;
    std::cout << "\n-------Pyramid--------\n";
    ptr->setter();
    std::cout << "\nArea of Pyramid : " << ptr->area() << std::endl;
    std::cout << "Volume of Pyramid : " << ptr->volume() << std::endl;
    //******Cube***********
    Cube cb;
    ptr = NULL;
    ptr = &cb;
    std::cout << "\n-------Cube------------\n";
    ptr->setter();
    std::cout << "\nArea of cube: " << ptr->area() << std::endl;
    std::cout << "Volume of cube : " << ptr->volume() << std::endl;
    //******Square***********
    Square sq;
    ptr = NULL;
    ptr = &sq;
    std::cout << "\n-------Square------------\n";
    ptr->setter();
    std::cout << "\nArea of Square: " << ptr->area() << std::endl;
    std::cout << "Color of Square: " << ptr->getColor() << std::endl;
    //******Circle***********
    Circle cr;
    ptr = NULL;
    ptr = &cr;
    std::cout << "\n-------Circle------------\n";
    ptr->setter();
    std::cout << "\nArea of Circle: " << ptr->area() << std::endl;
    std::cout << "Color of Cicle: " << ptr->getColor() << std::endl;

    return 0;
}
