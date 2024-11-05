Access Specifiers

#include <iostream>

class MyClass {
public:
    // Public member variables
    int publicVar;

    // Public member function
    void publicFunction() {
        std::cout<<publicVar<<std::endl;
        std::cout << "Public function called" << std::endl;
    }

private:
    // Private member variables
    int privateVar;

    // Private member function
    void privateFunction() {
        std::cout<<privateVar<<std::endl;
        std::cout << "Private function called" << std::endl;
    }

protected:
    // Protected member variables
    int protectedVar;

    // Protected member function
    void protectedFunction() {
        std::cout<<protectedVar<<std::endl;
        std::cout << "Protected function called" << std::endl;
    }
};

int main() {
    MyClass obj;

    // Accessing public member
    obj.publicVar = 1;
    obj.publicFunction();

    // Cannot access private members from outside the class
    // obj.privateVar = 2;       // Error: 'int MyClass::privateVar' is private within this context
    // obj.privateFunction();    // Error: 'void MyClass::privateFunction()' is private within this context

    // Cannot access protected members from outside the class
    // obj.protectedVar = 3;       // Error: 'int MyClass::protectedVar' is protected within this context
    // obj.protectedFunction();    // Error: 'void MyClass::protectedFunction()' is protected within this context

    return 0;
}

/*public: Members declared under the public access specifier
are accessible from outside the class.
They can be accessed by objects of the class,
as well as from functions outside the class.

private: Members declared under the private access specifier
are only accessible within the class itself.
They cannot be accessed directly by objects
of the class or from outside functions.

protected: Members declared under the protected access specifier
are accessible within the class itself and by its derived classes
(discussed in inheritance).
They are not directly accessible from outside the class.
