//Namespace provide the space where we can define or declare identifier i.e. variable,  method, classes.
//Using namespace, you can define the space or context
//in which identifiers are defined i.e. variable, method, classes.
//In essence, a namespace defines a scope.

#include <iostream>
using namespace std;
// first name space
namespace first_space
{
	void func()
	{
		cout << "Inside first_space" << endl;
	}
}

// second name space
namespace second_space
{
	void func()
	{
		cout << "Inside second_space" << endl;
	}
}
using namespace first_space;

int main ()
{
	// This calls function from first name space.
	func();
	return 0;
}
