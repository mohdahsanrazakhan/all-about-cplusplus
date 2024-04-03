#include<bits/stdc++.h>
using namespace std;

string findEquation(vector<pair<int, int>>& points) {
	int x1 = points[0].first, y1 = points[0].second;
	int x2 = points[1].first, y2 = points[1].second;
	double slope = (x2 != x1) ? (double)(y2 - 21) / (x2 - x1) : numeric_limits<double>::infinity();
	
	for(int i = 2; i < points.size(); i++) {
		int x = points[i].first, y = points[i].second;
		if((x - x1) == 0) {
			if(slope != numeric_limits<double>::infinity())
				return "0";
		} else if((double)(y - y1) / (x - x1) != slope) {
			return "0";
		}
	}
	
	int A = y1 - slope * x1;
	int B = -slope;
	int C = 0;
	if(B != 0) {
		return to_string(A) + "x + " + to_string(B) + "y + " + to_string(C) + " = 0";
	} else {
		return "x - " + to_string(A/B) + " = 0";
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	for(int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	
	cout << findEquation(points);
	return 0;
}
