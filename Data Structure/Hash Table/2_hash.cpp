#include<iostream>
#include<map>
using namespace std;

/* Example of map (ordered map)
 * Ordering is based on key
 * All the O(1) will be O(log(n)) in map -
 * - because it is internally work tree like data structure
 */
int main()
{
	map<string, int> menu;
	
	// Insert key value pairs inside the hashtable O(logN) operation
	menu["maggi"] = 15;
	menu["cola"] = 20;
	menu["dosa"] = 99;
	menu["pizza"] = 499;
	menu["samosa"] = 10;
	
	// Print the value of key
	cout << menu["dosa"] << endl;
	
	// Update price of dosa TC: O(logN)
	menu["dosa"] = (1 + 0.1)*menu["dosa"];
	
	// Deletion TC: O(logN)
	menu.erase("dosa");
	
	// Searching inside a collection of key value pairs (stored inside hash table) Time Complexity: O(N)
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
