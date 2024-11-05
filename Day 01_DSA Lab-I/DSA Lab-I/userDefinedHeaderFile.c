// Include your header file with “#include” in your C++ program
// C++ program to find the sum of two numbers using function declared in header file

#include <iostream>
#include <sum.h>
using namespace std;

int main()
{

	int a = 13, b = 22;

	// Function declared in header file to find the sum
	cout << "Sum is: " << sumOfTwoNumbers(a, b) << endl;
}
