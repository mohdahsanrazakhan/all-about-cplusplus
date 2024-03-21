#include<bits/stdc++.h>
using namespace std;

// Linear Search -> TC: O(N) | SC: O(1)
int linearSearch(int arr[], int findNum, int size) {
	
	for(int i = 0; i < size; i++) {
		if(arr[i] == findNum) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[]= {1, 2, 3, 4, 5};
	int num = 3;
	int sz = sizeof(arr)/sizeof(arr[0]);
	
	cout << linearSearch(arr, num, sz);
}
