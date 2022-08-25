#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

void NSL(vector<int> nums) {
	vector<int> v;
	stack<int> s;
	
	for(int i = 0; i < nums.size(); i++) {
		if(s.size() == 0)
			v.push_back(-1);
		else if(s.size() > 0 && s.top() < nums[i])
			v.push_back(s.top());
		else if(s.size() > 0 && s.top() >= nums[i]) {
			while(s.size() > 0 && s.top() >= nums[i])
				s.pop();
			if(s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(nums[i]);
	}
	for(auto it : v)
		cout << it << " ";
}

int main()
{
	vector<int> n = {4,5,2,10,8};
	NSL(n);
}

