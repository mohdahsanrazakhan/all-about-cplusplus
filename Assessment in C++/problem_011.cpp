#include<bits/stdc++.h>
using namespace std;

int maximumFrequencyCount(vector<int> arr, int n) {
	
	int maxi = 0, maxiVal = 0;
	map<int, int> mp;
	
	sort(arr.begin(), arr.end());
	
	for(int i = 0; i < n; i++) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = 1;
		}
		else {
			mp[arr[i]]++;
		}
	}
	
	for(auto it : mp) {
		if(it.second > maxi) {
			maxi = it.second;
			maxiVal = it.first;
		}
	}
	
	return maxiVal;
	
}

int main() {
	int n, num;
	cin >> n;
	vector<int> arr;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	
	cout << maximumFrequencyCount(arr, n);
}
