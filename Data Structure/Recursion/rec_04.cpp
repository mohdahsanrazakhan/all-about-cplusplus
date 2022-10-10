/*
 * Implementing recursion with static variable
 * Two ways: 
 * 1. Using static variable
 * 2. Using global variable
 */

#include<iostream>
using namespace std;

// Global variable
// int gVar;

int recSG(int n) {
	static int sVar = 0;
	if(n > 0) {
		sVar++;
		return recSG(n - 1) + sVar;
//		gVar++;
//		return recSG(n - 1) + gVar;
	}
}

int main() {
	int n;
	cin >> n;
	cout << recSG(n) << endl;
}

