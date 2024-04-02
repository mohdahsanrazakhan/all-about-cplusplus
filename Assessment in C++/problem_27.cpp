#include<bits/stdc++.h>
using namespace std;

string reverseString(string s) {
	
	int left = 0, right = s.length() - 1;
	string temp = "", result = "";
	
	while(left <= right) {
		char ch = s[left];
		if(ch != ' ') {
			temp += ch;
		} else if(ch == ' ') {
			if(result != "")
				result = temp + " " + result;
			else 
				result = temp;
			temp = "";
		}
		left++;
	}
	
	if(temp != "") {
		if(result != "")
			result = temp + " " + result;
		else
			result = temp;
	}
	return result;
}

int main() {
	string str;
	getline(cin, str);
	
	cout << reverseString(str);
}
