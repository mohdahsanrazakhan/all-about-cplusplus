#include<bits/stdc++.h>
using namespace std;

int OperationsBinaryString(char* str) {
	
	if(str == NULL) {
		return -1;
	}
	
	int i = 1;
	// Dereference the pointer str and subtract 
	// the ASCII value of '0' from the obtained character. 
	// Converts the character representation 
	// of a digit to its corresponding integer value.
	// Store this value in the variable a.
	int a = *str - '0'; 
	str++;
	
	while(*str != '\0') {
		char p = *str;
		str++;
		
		if(p == 'A')
			a &= (*str - '0');
		else if(p == 'B')
			a |= (*str - '0');
		else
			a ^= (*str - '0');
		
		str++;
	}
	return a;
}

int main() {
	string expStr;
	getline(cin, expStr);
	
	char *str = &expStr[0];
	
	cout << OperationsBinaryString(str);	
}
