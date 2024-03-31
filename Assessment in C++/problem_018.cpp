#include<bits/stdc++.h>
using namespace std;

int mostFrequentNumber(int arr[], int n) {
	
	map<int, int> mp;
	int mostFreq = 0, freq = 0;
	
	for(int i = 0; i < n; i++) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]] = 1;
		} else {
			mp[arr[i]]++;
		}
	}
	
	for(auto it : mp) {
		if(it.second > freq || (it.second == freq && it.first < mostFreq)) {
			freq = it.second;
			mostFreq = it.first;
		}
	}
	
	return mostFreq;
}


int main() {
	int tc, n;
	
	cin >> tc;
	
	for(int i = 0; i < tc; i++) {
		cin >> n;
		int arr[n];
		
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << mostFrequentNumber(arr, n) << endl;
	}
}
