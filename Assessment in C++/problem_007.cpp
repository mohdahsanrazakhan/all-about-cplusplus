#include<bits/stdc++.h>
using namespace std;

int LargeSmallSum(vector<int> arr) {
	
	int sz = arr.size();
	
	if(sz == 0 || sz <= 3) {
		return 0;
	}
	
	vector<int> evenArray;
	vector<int> oddArray;
	
	for(int i = 0; i < sz; i++) {
		if(i % 2 == 0) {
			evenArray.push_back(arr[i]);
		}
		else {
			oddArray.push_back(arr[i]);	
		}
	}
	
	int evenArraySize = evenArray.size();
	int oddArraySize = oddArray.size();
	
	sort(evenArray.begin(), evenArray.end());
	sort(oddArray.begin(), oddArray.end());
	
	return evenArray[evenArraySize-2] + oddArray[1];
}

int main() {
	int size, a = 0;
	cin >> size;
	vector<int> arr;
	
	for(int i = 0; i < size; i++) {
		cin >> a;
		arr.push_back(a);
	}
	
	cout << LargeSmallSum(arr);
}
