#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Using a temp array -> TC: O(N) | SC: O(k)	
void rotateToRight(int arr[], int n, int k) {
	// Edge Cases
	if(n == 0) return;
	k = k % n;
	if(k > n) return;
	
	int temp[k];
	
	for(int i = n-k; i < n; i++) {
		temp[i-n+k] = arr[i];
	}
	for(int i = n-k-1; i >= 0; i--) {
		arr[i+k] = arr[i];
	}
	for(int i = 0; i < k; i++) {
		arr[i] = temp[i];
	}
}

// Using a temp array -> TC: O(N) | SC: O(k)
void rotateToLeft(int arr[], int n, int k) {
    // Edge Cases	
	if(n == 0) return;
	k = k % n;
	if(k > n) return;
	
	int temp[k];
	
	for(int i = 0; i < k; i++) {
		temp[i] = arr[i];
	}
	for(int i = 0; i < n-k; i++) {
		arr[i] = arr[i+k];
	}
	for(int i = n-k; i < n; i++) {
		arr[i] = temp[i-n+k];
	}
}

// Optimal Approach
// Reversal Algorithm -> TC: O(N) | SC: O(1)
/* Function to Reverse the array */
void Reverse(int arr[], int start, int end) {
	
	while(start <= end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

/* Function to Rotate k elements to right */
void rightRotate(int arr[], int n, int k) {
	
	// Edge Cases
	if(n == 0) return;
	k = k % n;
	if(k > n) return;
 	
	// Reverse first n-k elements
	Reverse(arr, 0, n-k-1);
	
	// Reverse last k elements
	Reverse(arr, n-k, n-1);
	
	// Reverse whole array
	Reverse(arr, 0, n-1);
}

/* Function to Rotate k elements to left */
void leftRotate(int arr[], int n, int k) {
	
	// Edge Cases
	if(n == 0) return;
	k = k % n;
	if(k > n) return;
	
	// Rotate first k elements
	Reverse(arr, 0, k-1);
	
	// Rotate last n-k elements
	Reverse(arr, k, n-1);
	
	// Rotete whole array
	Reverse(arr, 0, n-1);
}


int main() {
	int arr[] = {1,2,3,4,5,6,7};
	int k = 9;
	int n = sizeof(arr)/sizeof(arr[0]);
	rotateToRight(arr, n, k);
	cout << "After rotating the elements to right: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	rotateToLeft(arr, n, k);
	cout << "After rotating the elements to left: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	rightRotate(arr, n, k);
	cout << "After rotating the elements to right: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	leftRotate(arr, n, k);
	cout << "After rotating the elements to left: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;	
	
	return 0;
}


// </> Ignore the below code. </>
//void rotateElements(int arr[], int n, int k, bool right) {
//	if(right == 1) {
//		// Right shift
//		vector<int> rightShift, shift;
//		
//		for(int i = n - k; i < n; i++) {
//			rightShift.push_back(arr[i]);
//		}
//		for(int i = 0; i < n - k; i++) {
//			shift.push_back(arr[i]);
//		}
//		int j = 0;
//		for(int rs : rightShift) {
//			arr[j++] = rs;
//		}
//		for(int s : shift) {
//			arr[j++] = s;
//		}
//		for(int i = 0; i < n; i++) {
//			cout << arr[i] << " ";
//		}
//	}
//	else {
//		// Left shift
//		vector<int> leftShift, shift;
//		
//		for(int i = 0; i < k; i++) {
//			leftShift.push_back(arr[i]);
//		}
//		for(int i = k; i < n; i++) {
//			shift.push_back(arr[i]);
//		}
//		int j = 0;
//		for(int s : shift) {
//			arr[j++] = s;
//		}
//		for(int ls : leftShift) {
//			arr[j++] = ls;
//		}
//		for(int i = 0; i < n; i++) {
//			cout << arr[i] << " ";
//		}
//	}
//}
