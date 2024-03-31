#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char *s1, int len, char ch1, char ch2) {
	
	for(int i = 0; i < len; i++) {
		if(s1[i] == ch1) {
			s1[i] = ch2;
		}
		else if(s1[i] == ch2) {
			s1[i] = ch1;
		}
	}
	

	cout << s1;
}

int main () {
	string str;
	getline(cin, str);
	int length = str.length();
	char ch1, ch2;
	cin >> ch1 >> ch2;
	
	char* s = new char[length + 1];
	
	strcpy(s, str.c_str());
	
	replaceCharacter(s, length, ch1, ch2);
	
	// Free memory allocated for character array
	delete[] s;
	
	return 0;
}
