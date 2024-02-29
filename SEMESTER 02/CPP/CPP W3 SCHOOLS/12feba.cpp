#include <iostream>
using namespace std;

int main() 
{
  cout << "Hello//*\t*// World!" << endl;
  //cout << "Hi India";
  int a=3, a1=2, a2, a3, a4;
  a2=a3=a4=5;
  cout << a4 << "\n";
  //int a1=2;
  cout << a /*"\n"*/ << endl;
  double b =13.98;
  cout << b << endl;
  char c='c';
  cout << c << endl;
  string d ="India Is Great";
  cout << d << endl;
  bool e = true; //true 1 false 0
  cout << e << endl;
  cout << "endl\n";
  cout << b << "\n" << "HI" << endl;
  cout << a/(double)a1 << endl;
  const int constantv = 3;
  //constantv = 4;
  /*const int minutesPerHour;
  minutesPerHour = 60; // error*/
  int x; 
  cout << "Type a number: "; // Type a number and press enter
  cin >> x; // Get user input from the keyboard
  cout << "Your number is: " << x << endl; // Display the input value
  // << insertion operator
  // >> extraction operator
  int x1, y1;
  cout << "Enter the value of x: ";
  cin >> x1;
  cout << "Enter the value of y: ";
  cin >> y1;
  cout << "x+y=" << x1+y1;
  
  
  
  
  return 0;
}
