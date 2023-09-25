// To-Do: 1) Write a Program to Calculate Sum of first N Natural
// Numbers (here value of N is Entered by user)

#include <iostream>
using namespace std;

int sumOfNumber(int n)
{
  int sum = 0, i;
  for (i = 0; i <= n; i++)
  {
    sum += i;
  }
  return sum;
}

int main()
{
  int num = 10;
  cin >> num;
  cout << sumOfNumber(num);
  return 0;
}

// To-Do: 2) Write a Program to Find Factorial of a given number N
// (N is entered by user)

#include <iostream>
using namespace std;

int factorial(int n)
{
  int fact = 1;
  for (int i = 1; i <= n; i++)
  {
    fact *= i;
  }
  return fact;
}

int main()
{
  int num = 5;
  cin >> num;
  cout << factorial(num);
  return 0;
}

// To-Do: 3) Write a Program to Generate Multiplication Table of a
// number (entered by the user) using a for loop.

#include <iostream>
using namespace std;

void generateTable(int n)
{

  for (int i = 1; i <= 10; i++)
  {
    cout << n << " * " << i << " = " << n * i << endl;
  }
}

int main()
{
  int tableOf = 5;
  generateTable(tableOf);
  return 0;
}

// 4 and 5 are same question
// To-Do: 4) Write a Program to Display Fibonacci Series upto nth
// term (n is entered by user)

// To-Do: 5) Write a Program to Display Fibonacci Series upto certain number n
// (n is entered by user)
// Example: n=100
// Output: Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89,

#include <iostream>
using namespace std;

void fibonacci(int n)
{
  int t1 = 0;
  int t2 = 1;
  int nextTerm = 0;

  for (int i = 1; i <= n; i++)
  {
    cout << t1 << ", ";
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }
}

int main()
{
  int num = 5;
  cin >> num;
  fibonacci(num);
  return 0;
}

// To-Do: 6) Write a Program to Find GCD or HCF of two numbers
// entered by user (Total 6 approach in GFG)

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  int res = min(a, b);
  while (res > 0)
  {
    if (a % res == 0 && b % res == 0)
    {
      break;
    }
    res--;
  }
  return res;
}

int main()
{
  int num1 = 10, num2 = 20;
  cin >> num1 >> num2;
  cout << gcd(num1, num2);
  return 0;
}

// To-Do: 7) Write a Program to Find LCM of two numbers entered
// by user

#include <iostream>
using namespace std;

int lcm(int a, int b)
{
  int maxNum, flag = 1;

  maxNum = (a > b) ? a : b;
  while (flag)
  {
    if (maxNum % a == 0 && maxNum % b == 0)
    {
      return maxNum;
      break;
    }
    ++maxNum;
  }
  return 0;
}

int main()
{
  int num1 = 12, num2 = 18;
  cin >> num1 >> num2;
  int lcmValue = lcm(num1, num2);
  cout << "LCM of " << num1 << " and " << num2 << " is: " << lcmValue << endl;
  return 0;
}

// To-Do: 8) Write a Program to Reverse a given Number N by user

#include <iostream>
using namespace std;

int revNum(int n)
{
  int revValue = 0;
  while (n > 0)
  {
    revValue = (revValue * 10) + (n % 10);
    n = n / 10;
  }
  return revValue;
}

int main()
{
  int num = 12345;
  cin >> num;
  cout << "Original Value: " << num << endl;
  cout << "Reversed Value: " << revNum(num);
  return 0;
}

// To-Do: 9) Write a Program to display sum of all digits of a given
// Number N by user

#include <iostream>
using namespace std;

int digitSum(int n)
{
  int sumOfAllDigit = 0;
  while (n > 0)
  {
    sumOfAllDigit += n % 10;
    n = n / 10;
  }
  return sumOfAllDigit;
}

int main()
{
  int num = 12345;
  cin >> num;
  cout << "Sum of " << num << " is " << digitSum(num) << endl;
  return 0;
}

// To-Do: 10) Write a Program to Calculate Power of a Number
// using inbuilt pow() function by taking two inputs from
// users as Base and exponent respectively

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int base = 2, exponent = 3;
  cin >> base >> exponent;
  cout << pow(base, exponent);
}

// To-Do: 11) Write a Program to Calculate Power of a Number
// without using inbuilt pow() function by taking two
// inputs from users as Base and exponent respectively

#include <iostream>
using namespace std;

int powerOf(int b, int e)
{
  int power = 1;
  for (int i = 1; i <= e; i++)
  {
    power *= b;
  }
  return power;
}

int main()
{
  int base = 2, exponent = 3;
  cin >> base >> exponent;
  cout << powerOf(base, exponent);
}

// To-Do: 12) Write a Program to Check Whether a Number N
// entered by user is Palindrome or Not

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num)
{
  string s = to_string(num);
  int len = s.length();

  for (int i = 0; i < len / 2; i++)
  {
    if (s[i] != s[len - 1 - i])
      return false;
  }
  return true;
}

int main()
{
  int num = 121;
  cin >> num;
  int res = isPalindrome(num);
  if (res == 1)
  {
    cout << num << " is a Palindrome" << endl;
    ;
  }
  else
  {
    cout << num << " is not a Palindrome" << endl;
  }
  return 0;
}
// To-Do: 13) Write a Program to Check Whether a Number is Prime
// or Not

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
  if (n <= 1)
  {
    return false;
  }

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int number = 2;
  cin >> number;
  int result = isPrime(number);
  if (result == 1)
  {
    cout << number << " is prime number";
  }
  else
  {
    cout << number << " is not a prime number";
  }
}

// To-Do: 14) Write a Program to Display Prime Numbers Between Two Intervals (entered by user)
// Example:
// Enter two numbers: 0 20
// Prime numbers between 0 and 20 are:
// 2 3 5 7 11 13 17 19

#include <iostream>
#include <cmath>
using namespace std;

void printPrimeNumberBetween(int from, int to)
{
  bool isPrime = false;

  while (from < to)
  {
    isPrime = true;

    if (from == 0 || to == 1)
    {
      isPrime = false;
    }

    for (int i = 2; i <= from / 2; i++)
    {
      if (from % i == 0)
      {
        isPrime = false;
        break;
      }
    }

    if (isPrime)
      cout << from << " ";

    from++;
  }
}

int main()
{
  int start = 0, end = 20;
  cin >> start >> end;
  printPrimeNumberBetween(start, end);
  return 0;
}

// To-Do: 15) Write a Program to check whether a number entered
// by the user is an Armstrong number or not.

#include <iostream>
#include <cmath>
using namespace std;

int isArmstrong(int n)
{
  int number = 0, calcArmstrongNumber = 0;

  while (n > 0)
  {
    number = n % 10;
    calcArmstrongNumber += pow(number, 3);
    n = n / 10;
  }

  return calcArmstrongNumber;
}

int main()
{
  int num = 153;
  cin >> num;
  int result = isArmstrong(num);
  (result == num) ? cout << num << " is a Armstrong Number" : cout << num << " is not a Armstrong Number";
  return 0;
}

// To-Do: 16) Write a Program to Display all Factors of a Number
// entered by User

#include <iostream>
using namespace std;

void printAllFactor(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cout << i << " ";
    }
  }
}

int main()
{
  int num = 60;
  cin >> num;
  printAllFactor(num);
  return 0;
}