/*
 * Tree Recursion: 
 * Calling itself more than one time.
 * TC: O(2^n)
 * SC: O(n)
 */

#include<iostream>
using namespace std;

void recTree(int n) {
	if(n > 0) {
		cout << n << " ";
		recTree(n-1);
		recTree(n-1);
	}
}

int main() {
	int n;
	cin >> n;
	recTree(n);
}

