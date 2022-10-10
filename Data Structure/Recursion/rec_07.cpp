/*
 * Nested Recursion:
 * Recursive function will pass the parameter as a recursive call.
*/

#include<iostream>
using namespace std;

int recNest(int n) {
	if(n > 100) {
		return n-10;
	}
	else {
		return recNest(recNest(n+11));
	}
}

int main() {
	int n;
	cin >> n;
	int r = recNest(n);
	cout << r << " ";
//	cout << recNest(n) << " ";
}

