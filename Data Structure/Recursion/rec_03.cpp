/*
 * Implementing recursion without static variable
 */

#include<iostream>
using namespace std;

int recWS(int n) {
	if(n > 0) {
		return recWS(n-1) + n;
	}
}

int main() {
	int n;
	cin >> n;
	cout << recWS(n) << " ";
}

