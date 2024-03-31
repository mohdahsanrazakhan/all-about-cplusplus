#include<bits/stdc++.h>
using namespace std;

int ProductSmallestPair(int sum, vector<int> arr) {
	
	int smallest = INT_MAX, secSmallest = INT_MAX, n = arr.size();
	
	if(n < 2) {
		return -1;
	}
	
	for(int i = 0; i < n; i++) {
		if(arr[i] < smallest) {
			smallest = arr[i];
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(arr[i] < secSmallest && arr[i] > smallest) {
			secSmallest = arr[i];
		}
	}
	
	if(smallest + secSmallest <= sum) {
		return smallest * secSmallest;
	} else {
		return 0;
	}
}

int main() {
	int sum, size, val;
	cin >> sum >> size;
	vector<int> arr;
	for(int i = 0; i < size; i++) {
		cin >> val;
		arr.push_back(val);
	}
	
	cout << ProductSmallestPair(sum, arr);
}
