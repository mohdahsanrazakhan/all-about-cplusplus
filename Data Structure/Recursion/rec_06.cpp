/*
 * Indirect Recursion:
 * More than one function and they are calling one another in a circular function.
*/

#include<iostream>
using namespace std;

void funcB(int n);

void funcA(int n) {
	if(n > 0) {
		cout << n << " ";
		funcB(n-1);
	}
}

void funcB(int n) {
	if(n > 0) {
		cout << n << " ";
		funcA(n/2);
	}
}

int main() {
	int n;
	cin >> n;
	funcA(n);
}

