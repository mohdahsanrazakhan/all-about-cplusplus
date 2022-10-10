#include<iostream>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[], int size) {
	int flag;
	for(int i = 0; i < size - 1; i++) {
		flag = 0;
		for(int j = 0; j < size - 1 - i; j++) {
			if(arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
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
	bubbleSort(arr, size);
	cout << endl << "After Bubble Sort: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

