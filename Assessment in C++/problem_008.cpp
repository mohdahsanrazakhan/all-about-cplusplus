#include<bits/stdc++.h>
using namespace std;

bool validateAnagram(string str1, string str2) {
	
	int sz1 = str1.size();
	int sz2 = str2.size();
	
	if(sz1 != sz2) {
		return false;
	}
	
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	cout << str1 << endl << str2 << endl;
	
	for(int i = 0; i < sz1; i++) {
		if(str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string str1, str2;
	
	getline(cin, str1);
	getline(cin, str2);
	
	if(validateAnagram(str1, str2)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}
