#include<bits/stdc++.h>
using namespace std;

void collatzSequence(int n) {
	
	while(n != 1) {
		
		cout << n << " ";	
			
		if(n % 2 == 0) {
			n /= 2;
		}
		else {
			n = 3*n+1;
		}
	}
	cout << n; // print 1
}

int main() {
	int n;
	cin >> n;
	collatzSequence(n);
}
