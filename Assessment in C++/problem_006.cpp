#include<bits/stdc++.h>
using namespace std;

int differenceofSum(int n, int m) {
	
	int sumOfNotDivByM = 0;
	int sumOfDivByM = 0;
	
	for(int i = 0; i <= n; i++) {
		i % m == 0 ? sumOfDivByM += i : sumOfNotDivByM += i;
	}
	
	return sumOfNotDivByM - sumOfDivByM;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	cout << differenceofSum(n,m);
}
