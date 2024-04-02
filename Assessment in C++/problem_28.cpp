#include<bits/stdc++.h>
using namespace std;

int sumOfDivisor(int n) {
	
	int sum = 0;
	
	for(int i = 1; i <= n; i++) {
		if(n%i == 0)
			sum += i;
	}
	
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	cout << sumOfDivisor(n);
}
