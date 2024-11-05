//we wish to use another version of cout that is custom implemented in some library called “foo”
#include <foo.h>
#include <iostream>
using namespace std;

cout << " Something to display";

//Namespaces were introduced into C++ to resolve identifier name conflicts.
//This ensured that two objects can have the same name and yet be treated differently
//if they belonged to different namespaces.
//Notice how the exact opposite has occurred in this example.
//Instead of resolving a name conflict, we actually create a naming conflict.

#include <foo>
#include <iostream>

// Use cout of std library
std::cout << "Something to display";

// Use cout of foo library
foo::cout < "Something to display";
