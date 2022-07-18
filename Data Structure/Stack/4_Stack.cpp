#include<iostream>
#include<cstring>
#include<stack>
#include<map>
using namespace std;

int isBalanced(char* exp)
{
	// create map
	map<char, char> mapping;
	mapping['}'] = '{';
	mapping[')'] = '(';
	mapping[']'] = '[';
	
	// create map iterator
	map<char, char>::iterator itr;
	
	// create stack
	stack<char> stk;
	
	for(int i = 0; i < strlen(exp); i++)
	{
		if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
		{
			stk.push(exp[i]);
		}
		else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if(stk.empty())
			{
				return false;
			}
			else
			{
				char temp = stk.top();
				itr = mapping.find(exp[i]);
				if(temp == itr->second) 
				{
					stk.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}
	return stk.empty() ? true : false;
}
	

int main()
{
	char E[] = "((a+b)*(c-d))";
	cout << isBalanced(E) << endl;
	
	char F[] = "((a+b)*(c-d)))";
	cout << isBalanced(F) << endl;
	
	char G[] = "(((a+b)*(c-d))";
	cout << isBalanced(G) << endl;
	return 0;
}

