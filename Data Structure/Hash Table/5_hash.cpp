/* unordered_set is awesome because is reduce the time complexity of searching in constant time O(1) */
#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	unordered_set<int> s{1,4,9,16,25,36,81};
	
	// insertion takes O(1)
	s.insert(121);
	
	// deletion takes O(1)
	s.erase(81);
	
	int key;
	cin >> key;
	
	// Advantage: find() function is a search function work in "constant time" - O(1)
	if(s.find(key) != s.end()) 
	{
		cout << key << " is present" << endl;
	}
	else
	{
		cout << key << " is not present" << endl;
	}
	
	// print all the elements of unordered set
	for(auto it : s)
	{
		cout << it << " ";
	}
	return 0;
}

