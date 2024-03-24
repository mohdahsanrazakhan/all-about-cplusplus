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

// Better Approach
// Using Hashing -> TC: O(N) + O(N) ~ O(2*N) | SC: O(N)
int missingNumberHash(vector<int> &arr, int N) {
	// Hash array initialize all index with 0
	int hash[N+1] = {0};
	
	// Storing the frequencies
	for(int i = 0; i < N - 1; i++) {
		hash[arr[i]]++;
	}
	
	// Checking the frequencies for number 1 to N
	for(int i = 1; i <= N; i++) {
		if(hash[i] == 0) {
			return i;
		}
	}
	
	// The following line will never execute.
	// It is just to avoid wornings.
	return -1;
}

// Optimal Approach I
// Summation Approach -> TC: O(N) | SC: O(1)
int missingNumberSummation(vector<int> &arr, int N) {
	// Summation of first N numbers
	int sum = (N * (N + 1)) / 2;
	
	// Summation of all array elements
	int sumAllElements = 0;
	for(int i = 0; i < N - 1; i++) {
		sumAllElements += arr[i];
	}
	
	int missingNum = sum - sumAllElements;
	return missingNum;
}

// Optimal Approach II
// XOR Approach -> TC: O(N) | SC: O(1)
int missingNumberXOR(vector<int> &arr, int N) {
	
	int xor1 = 0, xor2 = 0;
	
	for(int i = 0; i < N - 1; i++) {
		// XOR of array elements
		xor2 = xor2 ^ arr[i];
		// XOR up to [1...N-1]
		xor1 = xor1 ^ (i + 1);
	}
	// XOR up to [1...N]
	xor1 = xor1 ^ N;
	
	// The missing number
	return (xor1 ^ xor2);
}

int main() {
	vector<int> arr = {1,2,4,5};
	int N = 5;
	
	cout << "Missing Number using Naive is " << missingNumberNaive(arr, N) << endl;
	cout << "Missing Number using Brute is " << missingNumberBrute(arr, N) << endl;
	cout << "Missing Number using Hash is " << missingNumberHash(arr, N) << endl;
	cout << "Missing Number using Summation is " << missingNumberSummation(arr, N) << endl;
	cout << "Missing Number using XOR is " << missingNumberXOR(arr, N) << endl;
}
