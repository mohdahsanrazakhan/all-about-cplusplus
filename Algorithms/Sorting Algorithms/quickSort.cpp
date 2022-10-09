/*
 * Quick Sort: It is a sorting algorithm, which is based on the divide-and-conquer algorithm (which recursively breaks down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly.)
 * Time Complexity: Best Case - O(nlogn) || Worst Case - O(n^2)
*/

#include<iostream>
using namespace std;

// Swap function 
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// Pivot Partition
int partition(int arr[], int left, int right) {
	int pivot = arr[right];
	int i = left - 1;
	
	for(int j = left; j < right; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, right);
	return i + 1;
}

void quickSort(int arr[], int left, int right) {
	if(left < right) {
		int pi = partition(arr, left, right);
		quickSort(arr, left, pi - 1);
		quickSort(arr, pi + 1, right);
	}
}

int main() {
	int size;
	cin >> size;
	int arr[size];
	
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	
	// Without sorting an array 
	cout << "Original Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	// After sorting an array
	quickSort(arr, 0, size-1);
	cout << endl << "Sorted Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

