/*
 * Tail Recution: 
 * All operation perform during calling time only.
 * Function does not perform any operation during returning time.
 */

#include<iostream>
using namespace std;

/* 
 * TC: O(n)
 * SC: O(n)
 */
void recTail(int n) {
	if(n > 0) {
		// Print during calling
		cout << n << " ";
		recTail(n-1);
	}
}

/*
 * TC: O(n)
 * SC: O(1)
 */
void loopTail(int n) {
	while(n > 0) {
		cout << n << " ";
		n--;
	}
}

int main() {
	int n;
	cin >> n;
	recTail(n);
	cout << endl;
	loopTail(n);
}

