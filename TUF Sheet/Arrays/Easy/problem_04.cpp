#include<bits/stdc++.h>
using namespace std;

// Better Approach -> TC: O(N) | SC: O(N) 
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

int main() {
	int arr[] = {1,2,2,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << removeDuplicate(arr, n);
}
