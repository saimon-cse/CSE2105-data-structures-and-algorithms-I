//Class: A user-defined data type that serves as a blueprint for creating objects. It encapsulates data (attributes) and operations (member functions) into a single unit.
//In the example of class Car, the data member will be speed limit, mileage, etc and member functions can apply brakes, increase speed, etc.
//An Object is an identifiable entity with some characteristics and behavior.
//An Object is an instance of a Class.
//When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
//When a program is executed the objects interact by sending messages to one another.
//Each object contains data and code to manipulate the data.
//Objects can interact without having to know details of each other’s data or code, it is sufficient to know the type of message accepted and the type of response returned by the objects.

#include <iostream>

// Class definition
class Rectangle {
public:
    int width;
    int height;
};

//Access Specifier: public:public is an access specifier in C++ that specifies the visibility of class members. Public members are accessible from outside the class.
