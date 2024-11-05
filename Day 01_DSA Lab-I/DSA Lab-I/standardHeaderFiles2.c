//Standard Header Files/Pre-existing header files and their Uses

/*<iostream>
It contains declarations for input and output operations using streams, such as std::cout, std::cin, and std::endl

<cmath>
It is used to perform mathematical operations like sqrt(), log2(), pow(), etc.

<cstdlib>
Declares functions involving memory allocation and system-related functions, such as malloc(), exit(), and rand()

<cstring>
It is used to perform various functionalities related to string manipulation like strlen(), strcmp(), strcpy(), size(), etc.

<vector>
It is used to work with container class for dynamic arrays (vectors) functions like begin() , end().*/

// C++ program to demonstrate Standard header files

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// using <iostream>
	cout << "Hello World!" << endl;

	// using <cmath>
	double squareRoot = sqrt(25);
	cout << "Square root of 25 is: " << squareRoot << endl;

	// using<cstdlib>
	int randomNum = rand() % 100; // Generate a random
								// number between 0 and 99
	cout << "Random number is : " << randomNum << endl;

	// using <cstring>
	char mystr1[] = "Hello";
	char mystr2[] = " World";
	strcat(mystr1, mystr2);
	cout << "string after concatenation: " << mystr1
		<< endl;

	// using <vector>
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	cout << "Vector elements are: ";
	for (const auto& num : numbers) {
		cout << num << " ";
	}
	cout << endl;

	// using <string>
	string greeting = "Hello ";
	string name = "World";
	string fullGreeting = greeting + name;
	cout << "Greeting message: " << fullGreeting << endl;

	return 0;
}
