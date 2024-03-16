#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach -> TC: O(N*log(N))+O(N) | SC: O(N)
int removeDuplicateBrute(int arr[], int n) {
	
	set<int> set;
	
	for(int i = 0; i < n; i++) {
		set.insert(arr[i]);
	}
	int sz = set.size();
	int j = 0;
	for(int st: set) {
		arr[j++] = st;
	}
	return sz;
}

// Better Approach -> TC: O(N) | SC: O(N) (Note: Need to Fix)
int removeDuplicate(int arr[], int n) {
	
	vector<int> unique;
	
	for(int i = 1; i < n; i++) {
		if(arr[i] > arr[i-1]) {
			unique.push_back(arr[i-1]);
		}
		else {
			continue;
		}
	}
	unique.push_back(arr[n-1]);
	return unique.size();
}

// Optimal Approach -> TC: (Note: Need to Fix)
int removeDuplicateOptimal(int arr[], int n) {
	
	int i = 0;
	for (int j = 1; j < n; j++) {
	    if (arr[i] != arr[j]) {
	      i++;
	      arr[i] = arr[j];
	    }
	}
	return i + 1;
}

int main() {
	int arr[] = {1,1,2,2,2,3,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int rdb = removeDuplicateBrute(arr, n);
	int rd = removeDuplicate(arr, n);
	int rdo = removeDuplicateOptimal(arr, n);
	for(int i = 0; i < rdb; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int j = 0; j < rd; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	for(int k = 0; k < rdo; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
}
