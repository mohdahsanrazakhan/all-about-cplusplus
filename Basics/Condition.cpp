// To-Do: 1) Write a Program to Check Whether Number is Even or Odd

#include <iostream>
using namespace std;

bool checkEvenOdd(int num)
{
  if (num % 2 == 0)
    return true;
  else
    return false;
}

int main()
{
  int num = 0;
  cin >> num;
  cout << num << " is even? " << checkEvenOdd(num);
}

// To-Do: 2) Write a Program to Check Whether a Character is Vowel or Consonant.

#include <iostream>
using namespace std;

bool checkVowalConsonant(char ch)
{
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    return true;
  else
    return false;
}

int main()
{
  char ch = 'a';
  cin >> ch;
  cout << ch << " is vowal? " << checkVowalConsonant(ch);
}

// To-Do: 3) Write a Program to Find Largest Number Among Three Numbers entered by users

#include <iostream>
using namespace std;

int findLargestNumber(int a, int b, int c)
{
  if (a > b)
  {
    if (a > c)
    {
      return a;
    }
    else
    {
      return c;
    }
  }
  else
  {
    if (b > c)
    {
      return b;
    }
    else
    {
      return c;
    }
  }

  // if(a >= b && a >= c) {
  // 	return a;
  // }
  // else if(b >= a && b >= c) {
  // 	return b;
  // }
  // else {
  // 	return c;
  // }
}

int main()
{
  // int a = 1, b = 2, c = 3;
  int a, b, c;
  cin >> a >> b >> c;
  cout << findLargestNumber(a, b, c);
}

// To-Do: 4) Write a Program which accepts coefficients of a
// quadratic equation from the user and displays the roots
// (both real and complex roots depending upon the
// discriminant).

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float a = 4, b = 5, c = 1, root1, root2, discriminant, realPart, imaginaryPart;
  cin >> a >> b >> c;
  discriminant = b * b - 4 * a * c;

  if (discriminant > 0)
  {
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    cout << "Roots are real and different." << endl;
    cout << "root1 = " << root1 << endl;
    cout << "root2 = " << root2 << endl;
  }

  else if (discriminant == 0)
  {
    root1 = -b / (2 * a);
    cout << "Roots are real and same." << endl;
    cout << "root1 = root2 = " << root1 << endl;
  }

  else
  {
    realPart = -b / (2 * a);
    imaginaryPart = sqrt(-discriminant) / (2 * a);
    cout << "Roots are complex and different.";
    cout << "root1 = " << realPart << "+" << imaginaryPart << "i" << endl;
    cout << "root2 = " << realPart << "-" << imaginaryPart << "i" << endl;
  }

  return 0;
}

// To-Do: 5) Write a Program to Check whether a year entered by
// user is Leap Year or not

#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int year = 2000;
  cin >> year;
  int res = isLeapYear(year);
  cout << year << ((res == 1) ? " is a leap year." : " is not a leap year.");
  return 0;
}