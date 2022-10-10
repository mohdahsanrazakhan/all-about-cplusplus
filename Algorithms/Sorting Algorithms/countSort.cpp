#include<iostream>
using namespace std;

int Max(int arr[], int size) {
	int max = INT_MIN;
	for(int i = 0; i < size; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void countSort(int arr[], int size) {
	int max = Max(arr, size);
	
	// create count array
	int *count = new int [max + 1];
	
	// Initialize count array with 0
	for(int i = 0; i < max + 1; i++) {
		count[i] = 0;
	}
	
	// Update count array value based on array values
	for(int i = 0; i < size; i++) {
		count[arr[i]]++;
	}
	
	// Update array with sorted elements
	int i = 0, j = 0;
	while(j < max + 1) {
		if(count[j] > 0) {
			arr[i++] = j;
			count[j]--;
		}
		else {
			j++;
		}
	}
	
	// Delete heap memory
	delete[] count;
}

int main() {
	int size;
	cin >> size;
	int arr[size];
	
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	
	// Without Sorting
	cout << "Without Sorting: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	// After sotring
	countSort(arr, size);
	cout << endl << "After Count Sort: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

