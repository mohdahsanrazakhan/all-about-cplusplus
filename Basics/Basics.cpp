// To-Do: 1) Write a Program to print "Hello, World!"

#include <iostream>
using namespace std;

int main()
{
  cout << "Hello World";
  return 0;
}

// To-Do: 2) Write a Program to Print Integer Number Entered by User

#include <iostream>
using namespace std;

int printUserInput(int num)
{
  return num;
}

int main()
{
  int getNum = 0;
  cout << "Enter any number" << endl;
  cin >> getNum;
  cout << printUserInput(getNum);
  return 0;
}

// To-Do: 3) Write a Program to Add Two Integer Numbers Entered by User

#include <iostream>
using namespace std;

int sumTwoNumber(int num1, int num2)
{
  return num1 + num2;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << sumTwoNumber(a, b);
  return 0;
}

// To-Do: 4) Write a program where the user is asked to enter two
// integers (divisor and dividend) and the quotient and the
// remainder of their division is computed.(Both divisor and
// dividend should be integers.)

#include <iostream>
using namespace std;

void findQuotientAndRemainder(int dividend, int divisor)
{
  int quotient = dividend / divisor;
  int remainder = dividend % divisor;
  cout << "Quotient is : " << quotient << " and Reminder is : " << remainder << endl;
}

int main()
{
  int dividend, divisor;
  cin >> dividend >> divisor;
  findQuotientAndRemainder(dividend, divisor);
  return 0;
}

// To-Do: 5) Write a Program to Find Size of int, float, double and char in your computer

#include <iostream>
using namespace std;

int main()
{
  int i = 5;
  float f = 10.5;
  double d = 100.10;
  char c = 'a';

  cout << sizeof(i) << endl;
  cout << sizeof(f) << endl;
  cout << sizeof(d) << endl;
  cout << sizeof(c) << endl;
}

// To-Do: 6) Write a Program to Swap Two Numbers

#include <iostream>
using namespace std;

void swap(int a, int b)
{
  a = a + b;
  b = a - b;
  a = a - b;
  cout << "a = " << a << " b = " << b << endl;
}

int main()
{
  int a, b, temp = 0;
  cin >> a >> b;
  cout << "a = " << a << " b = " << b << endl;
  swap(a, b);

  return 0;
}

// To-Do: 7) Write a Program to Find ASCII Value of a Character (A = 65, Z = 90 and a = 97, z = 122)

#include <iostream>
using namespace std;

int main()
{
  char chA = 'A';
  char chZ = 'Z';
  char cha = 'a';
  char chz = 'z';
  cout << int(chA) << " " << int(chZ) << " " << int(cha) << " " << int(chz);
  return 0;
}

// To-Do: 8) Write a Program to Multiply two decimal Numbers entered by User

#include <iostream>
using namespace std;

float multiplyTwoDecimal(float a, float b)
{
  return a * b;
}

int main()
{
  float a, b;
  cin >> a >> b;
  cout << multiplyTwoDecimal(a, b);
  return 0;
}
