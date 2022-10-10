/*
 * Head Recursion: 
 * All operation perform during returning time only.
 * Function does not perform any operration at the time of calling
 */

#include<iostream>
using namespace std;

void recHead(int n) {
	if(n > 0) {
		recHead(n-1);
		// Print during returning
		cout << n << " "; 
	}
}

void loopHead(int n)
{
	int i = 1;
	while(n >= i) {
		cout << i << " ";
		i++;
	}
}

int main() {
	int n;
	cin >> n;
	recHead(n);
	cout << endl;
	loopHead(n);
}

