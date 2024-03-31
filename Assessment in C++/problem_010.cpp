#include<bits/stdc++.h>
using namespace std;

int numberOfCarry(int n1, int n2) {
	
	int cntCarry = 0, cnt = 0;
	
	string s1 = to_string(n1), s2 = to_string(n2);
	
	int length1 = s1.length(), length2 = s2.length();
	
	while(length1 != 0 || length2 != 0) {
		
		int x = 0, y = 0;
		
		if(length1 > 0) {
			x = s1[length1 - 1] - '0';
			length1--;
		}
		if(length2 > 0) {
			y = s2[length2 - 1] - '0';
			length2--;
		}
		
		int add = x + y + cntCarry;
		
		if(add >= 10) {
			cntCarry = 1;
			cnt++;
		}
		else {
			cntCarry = 0;
		}
	}
	
	return cnt;	
}

int main() {
	int num1, num2;
	
	cin >> num1 >> num2;
	
	cout << numberOfCarry(num1, num2);
}
