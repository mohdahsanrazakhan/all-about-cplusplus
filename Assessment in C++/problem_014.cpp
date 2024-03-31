#include<bits/stdc++.h>
using namespace std;

int operationChoices(int a, int b, int c) {
	
	int result = 0;
	
	switch(c) {
		case 1:
			result = (a+b);
			break;
		case 2:
			result = (a-b);
			break;
		case 3:
			result = (a*b);
			break;
		case 4:
			result = (a/b);
			break;
		default:
			cout << "Invalid Operator (value of c is between 1 to 4 inclusive)";
			break;
	}
	
	return result;
}

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	
	cout << operationChoices(a, b, c);
	
	return 0;
}
