#include<bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> arr, int n) {
	int minIdx, cntSwap = 0;
	
	for(int i = 0; i < n - 1; i++) {
		minIdx = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[minIdx])
				minIdx = j;
		}
		if(minIdx != i) {
			++cntSwap;
			swap(arr[minIdx], arr[i]);	
		}
	}
	
	for(auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
	
	return cntSwap;
}

int main() {
	int n, val;
	cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}
	
	cout << selectionSort(arr, n);
}
