#include<bits/stdc++.h>
using namespace std;

void maxInArray(int arr[], int n) {
	
	int maxVal = 0, idx = 0;
	
	for(int i = 0; i < n; i++) {
		
		if(arr[i] > maxVal) {
			maxVal = arr[i];
			idx = i;
		}
	}
	
	cout << maxVal << endl << idx;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	maxInArray(arr, n);
	
	return 0;
}
