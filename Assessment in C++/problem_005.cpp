#include<bits/stdc++.h>
using namespace std;

int findCount(int arr[], int length, int num, int diff) {
	
	int cnt = 0;
	
	for(int i = 0; i < length; i++) {
		if(abs(arr[i] - num) <= diff) 
			cnt++;
	}
	
	return cnt > 0 ? cnt : -1;
}

int main() {
	int length;
	cin >> length;
	
	int arr[length];
	for(int i = 0; i < length; i++) {
		cin >> arr[i];
	}
	int num, diff;
	cin >> num >> diff;
	
	cout << findCount(arr, length, num, diff);
}
