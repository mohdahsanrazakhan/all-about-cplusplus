#include<iostream>
#include<map>
#include<list>
using namespace std;

int main()
{
	map<string, list<string>> phonebook;
	
	phonebook["Marcus"].push_back("111111");
	phonebook["Marcus"].push_back("111112");
	phonebook["Marcus"].push_back("111113");
	
	phonebook["Mark"].push_back("222222");
	phonebook["Mark"].push_back("222224");
	phonebook["Mark"].push_back("222226");
	
	cout << phonebook["Mark"] << endl;
	
//	for(map<string, list<string>> numbers : phonebook)
//	{
//		cout << numbers.first << " - " numbers.second;
//	}
}

