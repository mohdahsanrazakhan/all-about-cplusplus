#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach (Naive) -> TC: O(N^2) | SC: O(1)
int numberAppearsOnceBrute(vector<int> &arr) {
	
	for(int i = 0; i < arr.size(); i++) {
		int count = 0;
		// Find the occurrence using linear search
		for(int j = 0; j < arr.size(); j++) {
			if(arr[i] == arr[j]) count++;
		}
		// If the occurrence is 1 return that element
		if(count == 1) return arr[i];	
	}
	return -1;
}

// Better Approach I
// Using Hashing -> TC: O(N)+O(N)+O(N) | SC: O(maxElement + 1)
int numberAppearsOnceBetterI(vector<int> &arr) {
	
	// Find the maximum element
	int maxElement = arr[0];
	for(int i = 0; i < arr.size(); i++) {
		maxElement = max(maxElement, arr[i]);
	}
	
	// Declare hash array of size maxElement + 1
	// And hash the given array
	vector<int> hash(maxElement + 1, 0);
	for(int i = 0; i < arr.size(); i++) {
		hash[arr[i]]++;
	}
	
	// Find the single element and return the answer
	for(int i = 0; i < arr.size(); i++) {
		if(hash[arr[i]] == 1) return arr[i];
	}
	return -1;
}

// Better Approach II
// Hashing using the map data structure -> TC: O(N*logM) + O(M) | SC: O(M)
int numberAppearsOnceBetterII(vector<int> &arr) {
	
	// Declare the hashmap and hash the given array
	map<int, int> hmp;
	for(int i = 0; i < arr.size(); i++) {
		hmp[arr[i]]++;
	}
	
	// Find the single element and return that element
	for(auto value : hmp) {
		if(value.second == 1)
			return value.first;
	}
	
	return -1;
}

// Optimal Approach
// XOR -> TC: O(N) | SC: O(1)
int numberAppearsOnceOptimal(vector<int> &arr) {
	
	// XOR all the elements
	int xorr = 0;
	for(int i = 0; i < arr.size(); i++) {
		xorr = xorr ^ arr[i];
	}
	return xorr;
}

int main() {
	vector<int> arr = {4,2,4,2,1};
	cout << "Brute Force Approach is " << numberAppearsOnceBrute(arr) << endl;
	cout << "Better Approach I is " << numberAppearsOnceBetterI(arr) << endl;
	cout << "Better Approach II is " << numberAppearsOnceBetterII(arr) << endl;
	cout << "Optimal Approach is " << numberAppearsOnceOptimal(arr) << endl;
}
