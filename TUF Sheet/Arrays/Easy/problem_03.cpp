#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
	// Edge case
	if(n < 2) 
		return true;
	
	int follow = INT_MIN, i;
	bool flag = false;
	
	for(i = 0; i < n; i++) {
		if(arr[i] >= follow) {
			follow = arr[i];
			flag = true;
		}
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int arr[] = {5, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << isSorted(arr, n);
}
