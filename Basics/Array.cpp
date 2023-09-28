// To-Do: 1) Write a Program that takes N elements (max. value of N is 100
// and N is the float number specified by user) from user, stores data
// in an array and Calculates the average of those numbers.

#include<iostream>
using namespace std;

float averageCalc(float arr[], int size) {
	float sum = 0, avg = 0;
	for(int i = 0; i < size; i++) {
		sum += arr[i];
	}

	avg = sum/size;

	return avg;
}

int main() {
	int N = 5;
	cin >> N;
	if(N <= 100) {
		float arr[N] = {0}, sum = 0, avg = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		cout << averageCalc(arr, N);
	}
	else {
		cout << "Please enter the value of N less than or equal to 100";
	}
}

// To-Do: 2) Write a Program that takes n element from user and displays
// the largest element of an array

#include<iostream>
#include<climits>
using namespace std;

int maxValue(int arr[], int n) {
	int maxi = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(arr[i] > maxi) {
			maxi = arr[i];
		}
	}
	return maxi;
}

int main() {
	int n = 3;
	cin >> n;
	int arr[n] = {1,2,3};

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << maxValue(arr, n);

}

// To-Do: 3) Write a Program that calculates the standard deviation of 10
// data using arrays

#include<iostream>
#include<cmath>
using namespace std;

int findMean(int arr[], int n) {
	int meanVal = 0;
	for(int i = 0; i < n; i++) {
		meanVal += arr[i];
	}

	return meanVal/n;
}

float findSqSubsMean(int arr[], int n, int meanVal) {
	float addAllValues = 0;
	float SD = 0;
	for(int i = 0; i < n; i++) {
		addAllValues += pow((arr[i] - meanVal), 2);
	}
	SD = addAllValues/n;
	return SD;
}

int main() {
	int sz = 10;
	cin >> sz;
	int arr[sz] = {3,2,4,5,6,7,9,1,2,3};

	for(int i = 0; i < sz; i++) {
		cin >> arr[i];
	}

	int mean = findMean(arr, sz);
	cout << "Mean: " << mean << endl;
	float subsMeanSq = findSqSubsMean(arr, sz, mean);
	cout << "Standard Deviation : " << subsMeanSq << endl;
}

// To-Do: 4) Write a Program that takes the array of five element and the
// elements of that array are accessed using pointer.

#include<iostream>
using namespace std;

int main() {
	int n = 5;
	cin >> n;
	int arr[n] = {1,2,3,4,5};

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++) {
		cout << *(arr + i) << " ";
	}

	return 0;
}

// To-Do: Get input from user and print.

#include<iostream>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;

	int arr[r][c];

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
