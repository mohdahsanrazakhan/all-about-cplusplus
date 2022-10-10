/*
 * Power using Recursion.
 */

#include<iostream>
using namespace std;

// Iterative way
int iPower(int m, int n) {
	int pow = 1;
	if(n == 0)
		return 1;
	while(n > 0) {
		pow *= m;
		n--;
	}
	return pow;
}

// Method 1
int power1(int m, int n) {
	if(n == 0) 
		return 1;
	else 
		return power1(m, n-1) * m;
}

// Method 2
int power2(int m, int n) {
	if(n == 0)
		return 1;
	if(n%2 == 0)
		return power2(m*m, n/2);
	else
		return m*power2(m*m, (n-1)/2);
}

int main() {
	int m,n;
	cin >> m >> n;
	cout << iPower(m,n) << endl;
	cout << power1(m,n) << endl;
	cout << power2(m,n) << endl;
	
}

