#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
	int rows = matrix.size(), cols = matrix[0].size();
	vector<int> result;
	
	if(rows == 0) return result;
	
	vector<vector<bool>> tracked(rows, vector<bool>(cols, false));
	int dr[] = { 0, 1, 0, -1};
	int dc[] = { 1, 0, -1, 0};
	
	int x = 0, y = 0, di = 0;
	
	// Iterate from 0 to rows*cols-1
	for(int i = 0; i < rows*cols; i++) {
		result.push_back(matrix[x][y]);
		
		tracked[x][y] = true;
		int newX = x + dr[di];
		int newY = y + dc[di];
		
		if(0 <= newX && newX < rows && 0 <= newY && newY < cols && !tracked[newX][newY]) {
			x = newX;
			y = newY;
		}
		else {
			di = (di + 1) % 4;
			x += dr[di];
			y += dc[di];
		}
	}
	return result;
}

int main() {
	vector<vector<int>> mtx{ { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };
                           
	for(int it : spiralOrder(mtx)) {
		cout << it  << " ";
	}
	return 0;
}
