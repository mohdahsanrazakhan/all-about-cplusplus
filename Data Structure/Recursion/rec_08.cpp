/*
 * Sum of Natural Number using Recursion.
 */

#include<iostream>
using namespace std;

// Simple Function TC: O(1)
int iSum(int n) {
	return n*(n+1)/2;
}

// Using loop TC: O(n) & SC: O(1)
int lSum(int n) {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

// Recursion TC: O(n) & SC: O(n)
int rSum(int n) {
	if(n == 0)
		return 0;
	else
		return rSum(n-1) + n;
}

int main() {
	int n;
	cin >> n;
	cout << iSum(n) << endl;
	cout << lSum(n) << endl;
	cout << rSum(n) << endl;
}

