//Write a program containing a possible exception. Use a try block to throw it and a catch block to handle it promptly.

//NOT DONE BY ME.

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << endl;
	try {
		int numerator = 10;
		int denominator = 0;
		int result;

		if (denominator == 0) 
        {
			throw runtime_error("Division by zero not allowed!");
		}
		result = numerator / denominator;
		cout << "Result after division: " << result << endl;
	}
	catch (const exception& e) 
    {
		cout << "Exception: " << e.what() << endl;
	}
    cout << endl;

	return 0;
}
