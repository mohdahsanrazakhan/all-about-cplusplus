#include<bits/stdc++.h>
using namespace std;

// Linear Search -> TC: O(N) | SC: O(1)
int countMaxConsecutOnes(vector<int> prices) {
	int maxConsecut = 0, count = 0, i;
	
	for(i = 0; i < prices.size(); i++) {
		if(prices[i] == 1) {
			count++;
		}
		else {
			maxConsecut = max(maxConsecut, count);
			count = 0;
		}
	}
	maxConsecut = max(maxConsecut, count);
	
	return maxConsecut;
}

int main() {
	vector<int> prices = {1, 1, 0, 1};
	cout << countMaxConsecutOnes(prices);	
	return 0;
}
