#include<bits/stdc++.h>
using namespace std;

int kthLargestNumber(int arr[], int n, int k) {
	
	if(k < 0 || k >= n) {
		return -1;
	}
	
	sort(arr, arr + n);
	
	return arr[n-k-1];
}

int main() {
	int n, k;
	cout << "Size of an array: ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements: ";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Value of k: ";
	cin >> k;
	
	cout << kthLargestNumber(arr,n,k);
	
	return 0;
}
