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

// Iterative Way
int BinarySearch(Array arr, int key)
{
	int low, mid, high;
	low = 0; 
	high = arr.length-1;
	
	while(low <= high)
	{
		mid = (low+high)/2;
		if(key == arr.A[mid])
		{
			return mid;
		}
		else if(key < arr.A[mid])
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return -1;
}

// Recursive Way
int rBinarySearch(int arr[], int low, int high, int key)
{
	int mid;
	if(low <= high)
	{
		mid = (low+high)/2;
		if(key == arr[mid])
		{
			return mid;
		}
		else if(key < arr[mid])
		{
			return rBinarySearch(arr, low, mid-1, key);
		}
		else
		{
			return rBinarySearch(arr, mid+1, high, key);
		}
	}
	return -1;
}

int main()
{
	Array arr = {{2,4,6,8,10},10,5};
	cout << BinarySearch(arr, 22) << endl;
	cout << rBinarySearch(arr.A, 0, arr.length, 10) << endl;
	Display(arr);
}

