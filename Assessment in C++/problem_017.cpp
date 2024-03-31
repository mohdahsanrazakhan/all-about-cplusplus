#include<bits/stdc++.h>
using namespace std;

void changeFrequentCharacter(char* str, char x) {
	
	map<char, int> mp;
	int length = strlen(str);
	
	for(int i = 0; i < length; i++) {
		if(str[i] == '\0') {
			continue;
		}
		if(mp.find(str[i]) == mp.end()) {
			mp[str[i]] = 1;
		} else {
			mp[str[i]]++;
		}
	}
	
	int maxFreq = 0;
	char maxFreqChar;
	
	for(auto it : mp) {
		if(it.second > maxFreq || (it.second == maxFreq && it.first < maxFreqChar)) {
			maxFreq = it.second;
			maxFreqChar = it.first;
		}
	}
	
	for(int i = 0; i < length; i++) {
		if(str[i] == maxFreqChar) {
			str[i] = x;
		}
	}
	
	cout << str;
	
}

int main() {
	string str;
	getline(cin, str);
	int length = str.length();
	char* s = new char[length+1];
	strcpy(s, str.c_str());
	char x; 
	cin >> x;
	
	changeFrequentCharacter(s, x);
	
	// Free memory allocated for character array
	delete[] s;
	return 0;
}
