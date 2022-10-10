#include<iostream>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int size) {
	for(int i = 0; i < size - 1; i++) {
		int k;
		for(int j = k = i; j < size; j++) {
			if(arr[j] < arr[k]) {
				k = j;
			}
		}
		swap(&arr[i], &arr[k]);
	}
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
	selectionSort(arr, size);
	cout << endl << "After Selection Sort: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

