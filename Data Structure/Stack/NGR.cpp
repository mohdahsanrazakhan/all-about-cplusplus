#include<bits/stdc++.h>
using namespace std;

void NGR(vector<int>& arr, int size)
{
	vector<int> v;
	stack<int> s;
	
	for(int i = size-1; i >= 0; i--) {
		if(s.size() == 0)
			v.push_back(-1);
		else if(s.size() > 0 && s.top() > arr[i])
			v.push_back(s.top());
		else if(s.size() > 0 && s.top() <= arr[i]) {
			while(s.size() > 0 && s.top() <= arr[i]) {
				s.pop();
			}
			if(s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(),v.end());
	for(auto it : v)
		cout << it << " ";
}

int main()
{
	vector<int> val = {1,3,0,0,1,2,4};
	int sz = val.size();
	// calling NGR function
	NGR(val, sz);
	return 0;
}

