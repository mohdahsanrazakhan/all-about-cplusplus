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

void Append(Array *arr, int val)
{
	if(arr->length < arr->size)
	{
		arr->A[arr->length++] = val;
	}
}

void Insert(Array *arr, int index, int val)
{
	if(index >= 0 && index <= arr->length)
	{
		for(int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i-1];
		}
		arr->A[index] = val;
		arr->length++;
	}
}

int main()
{
	Array arr = {{2,4,6,8,10},10,5};
	
	Append(&arr, 20);
	Insert(&arr, 2, 40);
	Display(arr);
}

