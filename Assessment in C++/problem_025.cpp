#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n) {
	
	int secLargest = -1, largest = INT_MIN;
	
	for(int i = 0; i < n; i++) {
		if(largest < arr[i]) {
			largest = arr[i];
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(arr[i] > secLargest && arr[i] < largest) {
			secLargest = arr[i];
		}
	}
	
	return secLargest;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;  i < n; i++) {
		cin >> arr[i];
	}
	
	cout << secondLargest(arr, n);
}
