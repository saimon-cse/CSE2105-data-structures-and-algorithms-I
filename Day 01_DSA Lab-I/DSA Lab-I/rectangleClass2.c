#include <iostream>

// Class definition
class Rectangle {
public:
    int width;
    int height;
};

int main() {
    // Create an object of the Rectangle class
    Rectangle rect;

    // Access public members
    rect.width = 5;
    rect.height = 3;

    std::cout << "Width: " << rect.width << ", Height: " << rect.height << std::endl;
    return 0;
}
