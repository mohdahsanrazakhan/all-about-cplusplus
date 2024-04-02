#include<bits/stdc++.h>
using namespace std;

int maxNumber(int arr[], int n) {
	
	vector<int> singleValued;
	string maxi;
	
	for(int i = 0; i < n; i++) {
		while(arr[i] != 0) {
			singleValued.push_back(arr[i]%10);
			arr[i] /= 10;
		}
	}
	
	sort(singleValued.begin(), singleValued.end());
	
	for(int i = singleValued.size() - 1; i >= 0; i--) {
		maxi += singleValued[i] + '0';
	}
	
	int maximum = stoi(maxi);
	
	return maximum;
}

int main() {
	int size;
	cin >> size;
	int arr[size];
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	
	cout << maxNumber(arr, size);
}
