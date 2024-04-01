#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {
	
	string reverseStr;
	
	reverse_copy(str.begin(), str.end(), back_inserter(reverseStr));
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != reverseStr[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	string str;
	getline(cin, str);
	
	cout << isPalindrome(str);
}
