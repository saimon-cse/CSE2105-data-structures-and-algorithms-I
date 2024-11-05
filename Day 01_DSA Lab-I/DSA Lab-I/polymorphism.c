//Polymorphism
//allows objects of different types to be treated uniformly through a common interface.

#include <iostream>
#include <vector>

// Base class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function (to be overridden)
};

// Derived classes
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

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the area() function
    double area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5.0, 3.0));  // Create a Rectangle object
    shapes.push_back(new Circle(2.5));          // Create a Circle object

    // Calculate and print area for each shape
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }

    // Cleanup dynamically allocated objects
    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
