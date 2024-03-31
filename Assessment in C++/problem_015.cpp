#include<bits/stdc++.h>
using namespace std;

int calculate(int m, int n) {
    int sum = 0;

    if (m > n) {
        swap(m, n);
    }
    
    for (int i = m; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            sum += i;
        }
    }
    
    return sum;
}

int main() {
	int m, n;
	cin >> m >> n;
	
	cout << calculate(m, n);
	
	return 0;
}
