#include<iostream>
using namespace std;

struct Array
{
	int A[10];
	int size;
	int length;
};

void Display(Array arr)
{
	for(int i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << " ";
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(Array *arr, int key)
{
	for(int i = 0; i < arr->length; i++)
	{
		if(key == arr->A[i])
		{
			/* Transposition
			 * swap(&arr->A[i], &arr->A[i-1]); 
			 */
			// Move to front/head
			swap(&arr->A[i], &arr->A[0]); 
			return i;
		}
	}
	return -1;
}

int main()
{
	Array arr = {{2,4,6,8,10},10,5};
	cout << LinearSearch(&arr, 6) << endl;
	Display(arr);
	return 0;
}

