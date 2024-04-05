#include<bits/stdc++.h>
using namespace std;

//Iterative Technique
int bubbleSort(int arr[], int n) {
	int cntSwap = 0;
	bool swapped;
	
	for(int i = 0; i < n-1; i++) {
		swapped = false;
		for(int j = 0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				++cntSwap;
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		// If no swaps were made in this pass, the array is already sorted
		if(!swapped)
			break;
	}
	
	return cntSwap;
}

// Optional
void display(int arr[], int n) {
	cout << "Sorted array: ";
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
//	int arr[] = {123, 21, 34, 45, 25, 675, 23, 44, 55, 900};
	int arr[] = {2, 1, 4, 6, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Number of swap count: " << bubbleSort(arr, n) << endl;
	display(arr, n);
}
