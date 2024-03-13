#include<bits/stdc++.h>
using namespace std;

// Brute-Fource Approach
// Sorting (if there are no duplicates number) -> TC: O(NlogN) | SC: O(1)
void getElements(int arr[], int n) {
	// Edge case
	if(n == 0 || n == 1) {
		cout << -1 << " " << -1 <<endl; 
	}
	sort(arr, arr+n);
	int secSmallest = arr[1];
	int secLargest = arr[n-2];
	cout << "Second smallest = " << secSmallest << endl;
	cout << "Second largest = " << secLargest << endl;
}

// Better Approach
// Using max(), min() and Conditions -> TC: O(N) | SC: O(1)
void getElementsBetter(int arr[], int n) {
	// Edge case
	if(n == 0 || n == 1) 
		cout << -1 << " " << -1 << endl;
		
	int smallest = INT_MAX, secSmallest = INT_MAX;
	int largest = INT_MIN, secLargest =INT_MIN, i;
	
	for(i = 0; i < n; i++) {
		smallest = min(smallest, arr[i]);
		largest = max(largest, arr[i]);
	}
	
	for(i = 0; i < n; i++) {
		if(arr[i] < secSmallest && arr[i] != smallest) 
			secSmallest = arr[i];
		if(arr[i] > secLargest && arr[i] != largest)
			secLargest = arr[i];
	}
	
	cout << "Second smallest = " << secSmallest << endl;
	cout << "Second largest = " << secLargest << endl;
}

int main() {
	int arr[] = {1,2,4,8,10,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	getElements(arr, n);
	getElementsBetter(arr, n);
	return 0;
}
