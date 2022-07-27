/* Any DS learning 2 question comes in mind:
 * 1. How does this DS work?
 * 2. How to use this DS?
*/

/* What is Hash Table
 * Hash Table is a container that stores key-value pairs. 
 * Hash Table is very fast. and the key-value pairs are not ordered (store in random order)
 
 * Hash Table is like a Menu 
 * Key   : Value
 * Cola  : 20
 * Maggi : 15
 * Dosa  : 100
 * Pizza : 199
 
 * Some Operations:
 * insert(key,value): to insert new key-value pair
 * search(key): to find a particular key
 * erase(key): to delete a particular key
 * Above operations are constant time complexity.
 
 * searching in array takes O(n) time complexity while in hash table takes O(1) time compleixty
 
 * Container Types:
 * Maps & Unordered_Maps (also known as hash table which stores key-value pair)
 * Sets & Unordered_Sets (it stores only keys)
 * Multimaps & Unordered Multimaps
 * These containers are used in -
 *    Array Problems
 *    Linked Lists Problems
 *    Sliding Window
 *    Graphs
 */

// Example of Hash Table (unordered_map)
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<string, int> menu;
	
	// Insert key value pairs inside the hashtable O(1) operation
	menu["maggi"] = 15;
	menu["cola"] = 20;
	menu["dosa"] = 99;
	menu["pizza"] = 499;
	menu["samosa"] = 10;
	
	// Print the value of key
	cout << menu["dosa"] << endl;
	
	// Update price of dosa TC: O(1)
	menu["dosa"] = (1 + 0.1)*menu["dosa"];
	
	// Deletion TC: O(1)
	menu.erase("dosa");
	
	// Searching inside a collection of key value pairs (stored inside hash table) Time Complexity: O(1)
	string item;
	cin >> item;
	
	// count() function will tell whether this 'item' is present inside the hash table or not
	if(menu.count(item) == 0)
		cout << item << " is not available" << endl;
	else
		cout << item << " is available, and its cost is " << menu[item] << endl;
	
	// Iterate over all the key-value pair that are present
	for(pair<string, int> item : menu)
	{
		cout << item.first << " - " << item.second << endl;
	}
	cout << endl;
	return 0;
}

/* Internally: It implements a technique called hashing with separate chaining. */

