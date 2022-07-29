/* Example 2: Pair Sum Problem 
 * Approaches:
 * 1. Brute Force (using two nested loops) TC: O(n^2)
 * 2. Sorting + Two Pointer | TC: O(NlogN)
 * 3. Sorting + Binary Search | TC: O(NlogN)
 * 4. Hashing (using unordered set) | TC: O(n)
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/* Time Complexity: O(n) */
void pairSum(vector<int> arr, int Sum)
{
	// Logic
	unordered_set<int> s;
	
	for(int i = 0; i < arr.size(); i++)
	{
		int x = Sum - arr[i];
		if(s.find(x) != s.end())
		{
			cout << x << " and " << arr[i] << endl;
		}
		// insert the current number inside set
		s.insert(arr[i]);
	}
}

int main()
{
	vector<int> arr{10, 5, 2, 3, -6, 9, 11, 2};
	int sum = 4;
	pairSum(arr, sum);
	return 0;
}

