#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach -> TC: O(N) | SC: O(N)
void leftRotateOne(int arr[], int n) {
	
	int temp[n];
	
	for(int i = 1; i < n; i++) {
		temp[i-1] = arr[i];
	}
	temp[n-1] = arr[0];
	
	for(int i = 0; i < n; i++) {
		cout << temp[i] << " ";
	}
}

// Optimal Approach -> TC: O(N) | SC: O(1)
void leftRotateOneOptimal(int arr[], int n) {
	
	int temp = arr[0];
	
	for(int i = 1; i < n; i++) {
		arr[i-1] = arr[i];
	}
	
	arr[n-1] = temp;
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	leftRotateOne(arr, n);
	cout << endl;
	leftRotateOneOptimal(arr, n);
}
