#include<bits/stdc++.h>
using namespace std;

int CheckPassword(char str[], int sz) {
	
	if(str[0] >= 0 && str[0] <= 9) {
		return 0;
	}
	
	for(int i = 0; i < sz - 1; i++) {
		if(str[i] == ' ' || str[i] == '/') {
			return 0;
		}
		if((str[i] >= 65 || str[i] <= 90) && (str[i] >= 0 || str[i] <= 9))
			return 1;
	}
}

int main() {
	char str[] = "aA1_67";
	int sz = sizeof(str)/sizeof(str[0]); // size + 1
	
	cout << CheckPassword(str, sz);
}
