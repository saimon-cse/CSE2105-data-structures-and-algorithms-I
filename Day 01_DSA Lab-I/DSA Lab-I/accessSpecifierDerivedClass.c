/*A pure virtual function in C++ is a virtual function
that has no implementation in the base class
and is meant to be overridden by derived classes.
declared with the virtual keyword and assigned the value 0 after its declaration.
This function serves as a placeholder within the base class,
defining an interface that derived classes must implement.*/

#include <iostream>

// Abstract base class
class Base {
public:
    // Pure virtual function
    virtual void doSomething() const = 0;
};

// Derived class implementing the pure virtual function
class Derived : public Base {
public:
    // Override the pure virtual function
    void doSomething() const override {
        std::cout << "Derived class doing something." << std::endl;
    }
};

int main() {
    // Create an object of the derived class
    Derived obj;
    // Call the overridden function
    obj.doSomething();
    return 0;
}
