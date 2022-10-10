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

int Delete(Array *arr, int index)
{
	int delVal = 0; 
	if(index >= 0 && index <= arr->length)
	{
		delVal = arr->A[index];
		for(int i = index; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
		return delVal;
	}
	return 0;
}

int main()
{
	Array arr = {{2,4,6,8,10},10,5};
	cout << "Deleted Value: " << Delete(&arr, 4) << endl;
	Display(arr);
}

