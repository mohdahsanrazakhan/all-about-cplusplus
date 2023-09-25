// To-Do: 1) Write a Program to Make a Simple Calculator to Add, Subtract, Multiply or Divide
// Using Switch case.
// The program should takes an arithmetic operator (+, -, *, /) and
// two operands from a user and performs the operation on those
// two operands depending upon the operator entered by the user.

#include <iostream>
using namespace std;

int main()
{
  int x = 5, y = 10;
  char aOperator = '+';
  cin >> x >> y >> aOperator;

  switch (aOperator)
  {
  case '+':
    cout << x + y << endl;
    break;

  case '-':
    cout << x - y << endl;
    break;

  case '*':
    cout << x * y << endl;
    break;

  case '/':
    cout << x / y << endl;
    break;

  default:
    cout << "Invalid Operator.\nPlease choose anyone of these operator (+, -, *, /)" << endl;
  }
}