#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {
	for(int i = 1; i < size; i++) {
		int j = i - 1;
		int x = arr[i];
		while(j > -1 && arr[j] > x) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
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
	insertionSort(arr, size);
	cout << endl << "After Insertion Sort: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

