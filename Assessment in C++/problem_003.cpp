#include<bits/stdc++.h>
using namespace std;

int ratCountHouse(int r, int unit, int n, int arr[]) {
	
	if(n == 0) {
		return -1;
	}
	
	int totalUnitEat = r * unit;
	int foodUnit = 0, i = 0;
	
	for(i = 0; i < n; i++) {
		foodUnit += arr[i];
		if(foodUnit >= totalUnitEat) {
			break;
		}
	}
	
	if(foodUnit < totalUnitEat) {
		return 0;
	}
	return i + 1;
}

int main() {
	int r, unit, n;
	cin >> r;
	cin >> unit;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << ratCountHouse(r,unit,n,arr);
}
