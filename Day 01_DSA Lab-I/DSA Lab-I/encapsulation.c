//encapsulation::data hiding
//bundling data (attributes) and methods (functions)
//into a single unit (class) and controlling access to them.
//It helps in hiding the internal implementation details
//of a class from the outside world.

#include <iostream>

class Circle {
private:
    double radius;  // Private data member

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Public member function to get area of circle
    double getArea() const {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle myCircle(5.0);  // Create a Circle object with radius 5.0

    // Accessing area using a public member function
    std::cout << "Area of circle: " << myCircle.getArea() << std::endl;

    // Attempting to access radius directly (which is private)
    // std::cout << "Radius of circle: " << myCircle.radius << std::endl; // Error: 'double Circle::radius' is private within this context

    return 0;
}
