//new Operator
//dynamically allocates memory for an object of a class on the heap
//returns a pointer to the allocated memory.

#include <iostream>

// Class definition
class Rectangle {
public:
    int width;
    int height;

    // Constructor
    Rectangle(int w, int h) : width(w), height(h) {}

    // Member function
    int area() {
        return width * height;
    }
};

int main() {
    // Dynamically allocate memory for an object of the Rectangle class
    Rectangle* rect_ptr = new Rectangle(5, 3);

    std::cout << "Area: " << rect_ptr->area() << std::endl;

    //deallocate memory
    delete rect_ptr;

    return 0;
}

/*In the provided code without using new,
the Rectangle object rect is created as a local variable within the main() function.
This means that rect is allocated on the stack,
and its memory is automatically deallocated when the main() function exits.
Fine for most scenarios, especially when the lifetime of the object is limited to the scope of the function.

However, using new dynamically allocates memory for the Rectangle object on the heap.
This allows the object to persist beyond the scope of the function where it was created.

Here are some scenarios where dynamically allocating memory using new might be necessary or beneficial:

Object Lifetime: If you need the object to persist beyond the scope
of the function where it was created, such as
when passing the object to other functions
or storing it in a data structure that outlives the function.

Dynamic Size: If the size of the object needs to be determined at runtime
or if the object needs to be resized dynamically.

Polymorphism: If you're working with polymorphic types
(i.e., using base class pointers to refer to derived class objects),
dynamic allocation is necessary to properly manage memory and avoid slicing.*/
