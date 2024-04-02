#include<bits/stdc++.h>
using namespace std;

int adamCharity(int n) {
	
	int charitySum = 0;
	
	for(int i = 1; i <= n; i++) {
		charitySum += pow(i,2); // means i*i
	}
	
	return charitySum;
}

int main() {
	int n;
	cin >> n;
	
	cout << adamCharity(n);
}
