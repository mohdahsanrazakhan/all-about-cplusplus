#include<bits/stdc++.h>
using namespace std;

// Using MAP -> TC: O((m+n)log(m+n)) | SC: O(m+n)
vector<int> unionTwoArraysMap(int arr1[], int arr2[], int m, int n) {
	
	map<int, int> unionMap;
	vector<int> Union;
	
	for(int i = 0; i < m; i++)
		unionMap[arr1[i]]++;
		
	for(int i = 0; i < n; i++)
		unionMap[arr2[i]]++;
	
	for(auto &it : unionMap) 
		Union.push_back(it.first);
	
	return Union;
}

// Using SET -> TC: O((m+n)log(m+n)) | SC: O(m+n)
vector<int> unionTwoArraysSet(int arr1[], int arr2[], int m, int n) {
	
	set<int> unionSet;
	vector<int> Union;
	
	for(int i = 0; i < m; i++)
		unionSet.insert(arr1[i]);
	
	for(int i = 0; i < n; i++)
		unionSet.insert(arr2[i]);
	
	for(auto &it : unionSet)
		Union.push_back(it);
	
	return Union;
}

// Using Two Pointer -> TC: O(m+n) | SC: O(1) 
vector<int> unionTwoArraysPointer(int arr1[], int arr2[], int m, int n) {
	
	int i = 0, j = 0;
	vector<int> Union;
	
	while(i < m && j < n) {
		// Case 1 and 2
		if(arr1[i] < arr2[j]) {
			if(Union.size() == 0 || Union.back() != arr1[i])
				Union.push_back(arr1[i]);
			i++;			
		}
		// Case 3
		else {
			if(Union.size() == 0 || Union.back() != arr2[j])
				Union.push_back(arr2[j]);
			j++;
		}
	}
	// If any elements left in arr1
	while(i < m) {
		if(Union.back() != arr1[i])
			Union.push_back(arr1[i]);
		i++;
	}
	while(j < n) {
		if(Union.back() != arr2[j])
			Union.push_back(arr2[j]);
		j++;
	}
	return Union;
}

int main() {
	int arr1[] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[] = {2,3,4,4,5,11,12};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	
	vector<int> UnionMap = unionTwoArraysMap(arr1, arr2, m, n);
	cout << "Union of arr1 and arr2 using MAP is ";
	for(auto &uValM : UnionMap) {
		cout << uValM << " ";
	}
	cout << endl;
	
	vector<int> UnionSet = unionTwoArraysSet(arr1, arr2, m, n);
	cout << "Union of arr1 and arr2 using SET is ";
	for(auto &uValS : UnionSet) {
		cout << uValS << " ";
	}
	cout << endl;
	
	vector<int> UnionPointers = unionTwoArraysPointer(arr1, arr2, m, n);
	cout << "Union of arr1 and arr2 using Two Pointers is ";
	for(auto &uValP : UnionPointers) {
		cout << uValP << " ";
	}
	
	return 0;
}
