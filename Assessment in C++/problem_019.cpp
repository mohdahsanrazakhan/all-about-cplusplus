#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArray(int a[], int b[], int aSize, int bSize) {
	
	vector<int> mergedArr;
	
	for(int i = 0; i < aSize; i++) {
		mergedArr.push_back(a[i]);
	}
	
	for(int i = 0; i < bSize; i++) {
		mergedArr.push_back(b[i]);
	}
	
	sort(mergedArr.begin(), mergedArr.end());

	return mergedArr;
}

int main() {
	int m, n;
	cin >> m;
	int arr[m];
	for(int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	cin >> n;
	int brr[n];
	for(int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	
	vector<int> merged = mergeArray(arr, brr, m, n);
	
	for(auto it : merged) {
		cout << it << " ";
	}
	return 0;
}
