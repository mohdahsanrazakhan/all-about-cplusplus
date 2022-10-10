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

int Get(Array arr, int index)
{
	if(index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
	return -1;
}

void Set(Array *arr, int index, int val)
{
	if(index >= 0 && index < arr->length)
	{
		arr->A[index] = val;
	}
}

int Max(Array arr)
{
	int max = arr.A[0];
	for(int i = 0; i < arr.length; i++)
	{
		if(arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}

int Min(Array arr)
{
	int min = arr.A[0];
	for(int i = 0; i < arr.length; i++)
	{
		if(arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}

int Sum(Array arr)
{
	int sumVal = 0;
	for(int i = 0; i < arr.length; i++)
	{
		sumVal += arr.A[i];
	}
	return sumVal;
}

float Avg(Array arr)
{
	return (float)Sum(arr)/arr.length;
}

int main()
{
	struct Array arr = {{2,4,6,8,10},10,5};
	
	cout << Get(arr,4) << endl;
	Set(&arr, 0, 15);
	cout << Max(arr) << endl;
	cout << Min(arr) << endl;
	cout << Sum(arr) << endl;
	cout << Avg(arr) << endl;
	
	Display(arr);
}

