#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int sz) {
	int largest = INT_MIN, secLargest = INT_MIN;
	for(int i = 0; i < sz; i++) {
		if(arr[i] > largest) {
			largest = arr[i];
		}
	}
	
	for(int i = 0; i < sz; i++) {
		if(arr[i] > secLargest && arr[i] < largest) {
			secLargest = arr[i];
		}
	}
	
	return secLargest;
}

int solve(int matrix[], int sz) {
	int evenMatrix[sz] = {0}, oddMatrix[sz] = {0}, evenIndex = 0, oddIndex = 0;
	
	for(int i = 0; i < sz; i++) {
		if(i % 2 == 0)
			evenMatrix[evenIndex++] = matrix[i];
		else 
			oddMatrix[oddIndex++] = matrix[i];
	}
	
	int evenSize = sizeof(evenMatrix)/sizeof(evenMatrix[0]);
	int oddSize = sizeof(oddMatrix)/sizeof(oddMatrix[0]);
	
	sort((evenMatrix), evenMatrix+evenSize);
	sort((oddMatrix), oddMatrix+oddSize);
	
	for(int i = 0; i < evenSize; i++) {
		cout << evenMatrix[i] << ' ';
	}
	cout << endl;
	for(int i = 0; i < oddSize; i++) {
		cout << oddMatrix[i] << ' ';
	}
	cout << endl;
	
	int secLargestOfEven = secondLargest(evenMatrix, evenSize);
	int secLargestOfOdd = secondLargest(oddMatrix, oddSize);
	
	return secLargestOfEven + secLargestOfOdd;
		
}

int main() {
	int sizeOfArray = 0;
	cin >> sizeOfArray;
	int matrix[sizeOfArray];
	for(int i = 0; i < sizeOfArray; i++) {
		cin >> matrix[i];
	}
	cout << solve(matrix, sizeOfArray);
}
