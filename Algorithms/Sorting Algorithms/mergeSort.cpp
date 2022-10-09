/*
 * Merge Sort: It is a sorting algorithm, which is based on the divide-and-conquer algorithm (which recursively breaks down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly.)
 * Time Complexity: O(nlogn)
 */

#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	// size of splitted array
	int sizeOne = mid - left + 1;
	int sizeTwo = right - mid;
	
	// temp arrays
	int A[sizeOne];
	int B[sizeTwo];
	
	// Storing elemennt in temp array
	for(int i = 0; i < sizeOne; i++) {
		A[i] = arr[left + i];
	}
	
	for(int i = 0; i < sizeTwo; i++) {
		B[i] = arr[mid + 1 + i];
	}
	
	// Creating two pointer, that points to both array at index 0
	int i = 0, j = 0;
	// Creating  a pointer, that ponits to left of an array.
	int k = left;
	
	// Store elements in sorted order in `arr`
	while(i < sizeOne && j < sizeTwo) {
		if(A[i] < B[j]) {
			arr[k] = A[i];
			k++, i++;
		}
		else {
			arr[k] = B[j];
			k++, j++;
		}
	}
	
	// If one array reach last index and second array remains to have value then store the remaining value in `arr`
	while(i < sizeOne) {
		arr[k] = A[i];
		k++, i++;
	}
	
	while(j < sizeTwo) {
		arr[k] = B[j];
		k++, j++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		
		merge(arr, left, mid, right);
	}
}

int main() {
	int size;
	cin >> size;
	int arr[size];
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	// Without sorting
	cout << "Original Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	// After sorting an array
	mergeSort(arr, 0, size-1);
	cout << endl << "Sorted Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}

