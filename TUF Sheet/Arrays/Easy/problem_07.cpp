#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach -> TC: O(N) + O(X) + O(N-X) ~ O(2*N) | SC: O(N)
void moveZeroToEndBrute(int arr[], int n) {
	
	vector<int> temp;
	
	for(int i = 0; i < n; i++) {
		if(arr[i] != 0)
			temp.push_back(arr[i]); 
	}
	
	int nzSize = temp.size();
	
	for(int i = 0; i < nzSize; i++) {
		arr[i] = temp[i];
	}
	
	for(int i = nzSize; i < n; i++) {
		arr[i] = 0;
	}
	
}

// Better Approach -> TC: O(N log N) | SC: O(1)
void moveZeroToEndBetter(int arr[], int n) {
	
	sort(arr, arr+n, greater<int>());
	
}

// Optimal Approach -> TC: | SC:
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}


int main() {
	int arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> a = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int sz = a.size();
	
	moveZeroToEndBrute(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	moveZeroToEndBetter(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	vector<int> result = moveZeros(sz, a);
    for (auto &it : result) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
