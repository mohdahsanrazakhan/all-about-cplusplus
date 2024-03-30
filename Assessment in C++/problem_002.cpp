#include<bits/stdc++.h>
using namespace std;

int CheckPassword(char str[], int sz) {
	
	// If less then 4, return 0
	if(sz < 4) {
		return 0;
	}
	
	// if starting character is a number, return 0
	// str[0] - '0' -> Converts the character representation 
	// of a digit to its corresponding integer value.
	if(str[0] - '0' >= 0 && str[0] - '0' <= 9) {
		return 0;
	}
	
	int idx = 0, capitalCnt = 0, numberCnt = 0;
	
	while(idx < sz) {
		// if space or / is present, return 0
		if(str[idx] == ' ' || str[idx] == '/') {
			return 0;
		}
		if(str[idx] >= 65 && str[idx] <= 90) {
			capitalCnt++;
		}
		if(str[idx] - '0' >= 0 && str[idx] - '0' <= 9) {
			numberCnt++;
		}
		idx++;
	}
	
	return capitalCnt > 0 && numberCnt > 0;
}

int main() {
	string pwdStr;
	getline(cin, pwdStr);
	int sz = pwdStr.size();
	char *str = &pwdStr[0];
	
	cout << CheckPassword(str, sz);
	
	return 0;
}
