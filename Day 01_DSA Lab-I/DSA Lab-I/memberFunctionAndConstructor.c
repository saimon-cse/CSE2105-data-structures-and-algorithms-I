//Member functions: Functions that are defined inside a class
//and can access the class's data members.
//They define the behavior of the class.

#include <iostream>

// Class definition
class Rectangle {
public:
    int width;
    int height;

    // Constructor: A special member function of a class
    // automatically called when an object is created.
    // initializes the object's data members.
    Rectangle(int w, int h) : width(w), height(h) {}

    // Member function
    int area() {
        return width * height;
    }
};

int main() {
    // Create an object of the Rectangle class with constructor
    Rectangle rect(5, 3);

    std::cout << "Area: " << rect.area() << std::endl;
    return 0;
}
