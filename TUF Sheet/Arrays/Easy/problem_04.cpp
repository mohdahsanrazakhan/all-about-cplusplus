#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach -> TC: O(N*log(N))+O(N) | SC: O(N)
int removeDuplicatesBrute(int arr[], int n) {
    
    set<int> set;
    
    for(int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }
    
    int sz = set.size();
    int i = 0;
    for(int st: set) {
        arr[i++] = st;
    }
    
    return sz;
}

// Better Approach -> TC: O(N) | SC: O(N)
int removeDuplicates(int arr[], int n) {
    
    vector<int> unique;
	
	for(int i = 1; i < n; i++) {
		if(arr[i] != arr[i-1]) {	
			unique.push_back(arr[i-1]);
		}
		else {
			continue;
		}
	}
	
	unique.push_back(arr[n-1]);
	
	int sz = unique.size(),i = 0;
	
	for(int uni : unique) {
	    arr[i++] = uni;
	}
	
	return sz;
}

// Optimal Approach -> TC: O(N) | SC: O(1)
int removeDuplicatesOptimal(int arr[], int n) {
    int i = 0;
	for (int j = 1; j < n; j++) {
	    if (arr[i] != arr[j]) {
	      i++;
	      arr[i] = arr[j];
	    }
	}
	return i + 1;
}

int main()
{
    int tc1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tc2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int tc3[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7};
    int n1 = sizeof(tc1)/sizeof(tc1[0]);
    int n2 = sizeof(tc2)/sizeof(tc2[0]);
    int n3 = sizeof(tc3)/sizeof(tc3[0]);
    int x = removeDuplicatesBrute(tc1, n1);
    int y = removeDuplicates(tc2, n2);
    int z = removeDuplicatesOptimal(tc3, n3);
    
    for(int i = 0; i < x; i++) {
        cout << tc1[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < y; i++) {
        cout << tc2[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < z; i++) {
        cout << tc3[i] << " ";
    }

    return 0;
}

