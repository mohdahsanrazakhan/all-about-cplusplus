#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach -> TC: O(N^2) | SC: O(1)
bool isSortedBrute(int arr[], int n) {
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
				return false;
			}
		}
	}
	return true;
}

// Better Approach -> TC: O(N) | SC: O(1)
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

// Optimal Approach -> TC: O(N) | SC: O(1)
bool isSortedOptimal(int arr[], int n) {
	
	for(int i = 1; i < n; i++) {
		if(arr[i] < arr[i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int arr[] = {5, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << isSortedBrute(arr, n) << endl;
	cout << isSorted(arr, n) << endl;
	cout << isSortedOptimal(arr, n) << endl;
}
