/*
 * Factorial using Recursion.
 */

#include<iostream>
using namespace std;

// Recursive Function
int rFact(int n) {
	if(n == 0)
		return 1;
	else
		return rFact(n-1)*n;
}

// Iterative Function
int iFact(int n) {
	int factorial = 1;
	for(int i = 1; i <= n; i++) {
		factorial *= i;
	}
	return factorial;
}

int main() {
	int n; 
	cin >> n;
	cout << rFact(n) << endl;
	cout << iFact(n) << endl;
}

