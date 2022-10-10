#include<iostream>
using namespace std;

struct DArray
{
	int *A;
	int size;
	int length;
};

void Display(DArray darr)
{
	for(int i = 0; i < darr.length; i++)
	{
		cout << darr.A[i] << " ";
	}
}

int main()
{
	DArray darr;
	int n, i;
	cout << "Enter size of an array: ";
	cin >> darr.size;
	
	// Creating an array in heap memory
	darr.A = new int[darr.size];
	darr.length = 0;
	
	cout << "Enter number of numbers: ";
	cin >> n;
	
	cout << "Enter all Elements: ";
	for(i = 0; i < n; i++) 
	{
		cin >> darr.A[i];
	}
	darr.length = n;
	
	Display(darr);
	return 0;
}

