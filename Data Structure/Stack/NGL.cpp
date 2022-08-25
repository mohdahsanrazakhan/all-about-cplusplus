#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void NGL(vector<int>& arr, int size) {
	vector<int> v;
	stack<int> s;
	for(int i = 0; i < size; i++) {
		if(s.size() == 0) 
			v.push_back(-1);
		else if(s.size() > 0 && s.top() > arr[i])
			v.push_back(s.top());
		else if(s.size() > 0 && s.top() <= arr[i]) {
			while(s.size() > 0 && s.top() <= arr[i])
				s.pop();
			if(s.size() == 0)
				v.push_back(-1);
			else 
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	for(auto it : v)
		cout << it << " ";
};

int main()
{
	vector<int> val = {1,3,2,4};
	int size = val.size();
	// Calling NGL function
	NGL(val, size);
}

