//Inheritance
//A mechanism where a class (subclass or derived class)
//can inherit properties and behaviors from another class (base class or superclass).

#include <iostream>

// Base class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function (to be overridden)
};

// Derived class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the area() function
    double area() const override {
        return length * width;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);  // Create a Rectangle object

    // Accessing area using inheritance
    std::cout << "Area of rectangle: " << rect.area() << std::endl;

    return 0;
}
