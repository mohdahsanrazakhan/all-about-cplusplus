#include <bits/stdc++.h> 
using namespace std;

// Brute Force Approach
// Sorting -> TC: O(N*log(N)) | SC: O(N)
int sortArr(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	return arr[arr.size()-1];
}

// Optimal Approach
// A max Value -> TC: O(N) | SC: O(1)
int largestElement(vector<int> &arr, int n) {
    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
	vector<int> arr = {2,8,9,1,10,5};
	int size = 6;
	cout << sortArr(arr) << endl;
	cout << largestElement(arr, size);
	return 0;
}
