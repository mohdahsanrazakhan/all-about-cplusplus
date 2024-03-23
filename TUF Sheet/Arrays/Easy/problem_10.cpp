#include<bits/stdc++.h>
using namespace std;

// Naïve Approach -> TC: O(N) | SC: O(1)
// Only work on sorted array.
int missingNumberNaive(vector<int> &arr, int N) {
	int findNum = 0;
	
	for(int i = 1; i < N; i++) {
		if(arr[i-1]+1 == arr[i])
			continue;
		else {
			findNum = arr[i-1]+1;
			break;
		}
	}
	return findNum;
}

// Brute Force Approach -> TC: O(N^2) | SC: O(1)
int missingNumberBrute(vector<int> &arr, int N) {
	
	// Outer loop that runs from 1 to N
	for(int i = 1; i < N; i++) {
		
		// flag check if an element is exists
		int flag = 0;
		
		// Search the element using linear search:
		for(int j = 0; j < N - 1; j++) {
			if(arr[j] == i) {
				
				// i is present in the array;
				flag = 1;
				break;
			}
		}
		
		// check if the element is missing
		// i.e flag == 0
		if(flag == 0) return i;
	}
	
	// The following line will never execute. 
	// It is just to avoid warnings
	return -1;
}

int main() {
	vector<int> arr = {1,2,4,5};
	int N = 5;
	
	cout << "Missing Number is " << missingNumberNaive(arr, N) << endl;
	cout << "Missing Number is " << missingNumberBrute(arr, N) << endl;
}
