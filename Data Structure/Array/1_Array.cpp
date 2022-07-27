#include<iostream>
using namespace std;

struct Array
{
	int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i; 
	for(i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << " ";
	}
}

int main()
{
	Array arr = {{2,4,6,8,10},10,5};
	cout << "Elements are: ";
	Display(arr);
	cout << endl << "Length: " <<  arr.length;
	cout << endl << "Size: " << arr.size;	
}

