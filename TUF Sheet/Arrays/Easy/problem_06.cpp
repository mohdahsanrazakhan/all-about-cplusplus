#include<bits/stdc++.h>
using namespace std;

void rotateElements(int arr[], int n, int k, bool right) {
	if(right == 1) {
		// Right shift
		vector<int> rightShift, shift;
		
		for(int i = n - k; i < n; i++) {
			rightShift.push_back(arr[i]);
		}
		for(int i = 0; i < n - k; i++) {
			shift.push_back(arr[i]);
		}
		int j = 0;
		for(int rs : rightShift) {
			arr[j++] = rs;
		}
		for(int s : shift) {
			arr[j++] = s;
		}
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
	else {
		// Left shift
		vector<int> leftShift, shift;
		
		for(int i = 0; i < k; i++) {
			leftShift.push_back(arr[i]);
		}
		for(int i = k; i < n; i++) {
			shift.push_back(arr[i]);
		}
		int j = 0;
		for(int s : shift) {
			arr[j++] = s;
		}
		for(int ls : leftShift) {
			arr[j++] = ls;
		}
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
}


int main() {
	int arr[] = {1,2,3,4,5,6,7};
	int k = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	bool right = 1;
	rotateElements(arr, n, k, right);
	return 0;
}
