#include <iostream>
using namespace std;

namespace Math 
{
  int add(int a, int b) 
  {
    return a + b;
  }
}

namespace Text 
{
  string greet(string name) 
  {
    return "Hello, " + name + "!";
  }
}

int main() 
{
    cout << endl;

    int result = Math :: add(3, 4);
    cout << "Result of addition: " << result << endl;

    string message = Text :: greet("World");
    cout << message << endl;

    cout << endl;

    return 0;
}
