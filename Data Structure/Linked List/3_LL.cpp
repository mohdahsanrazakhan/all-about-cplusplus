#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *first;
public:
	LinkedList() { first = NULL; }
	LinkedList(int A[], int size);
	~LinkedList();
	
	void Display();
	void Insert(int index, int val);
	int Delete(int index);
	int Length();
};

// Constructor: It is used to initialize the object of the class.
LinkedList::LinkedList(int A[], int size) 
{
	Node *temp, *last;
	
	first  = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;
	
	for(int i = 1; i < size; i++) 
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
};

// Destructor: It is called by the compiler when the object is destroyed.
LinkedList::~LinkedList()
{
	Node *p = first;
	while(first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

// Display function
void LinkedList::Display()
{
	Node *p = first;
	
	while(p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// Length function
int LinkedList::Length()
{
	Node *p = first;
	int len = 0;
	
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}

// Insert function
void LinkedList::Insert(int index, int val)
{
	Node *temp, *p = first;
	
	if(index < 0 || index > Length())
		return;
	temp = new Node;
	temp->data = val;
	temp->next = NULL;
	
	if(index == 0)
	{
		first = temp;
	}
	else
	{
		for(int i = 0; i < index - 1; i++)
			p = p->next;
		temp->next = p->next;
		p->next = temp;
	}
}

// Delete function
int LinkedList::Delete(int index)
{
	Node *p, *q = NULL;
	int val = -1;
	
	if(index < 1 || index > Length())
		return -1;
	if(index == 1)
	{
		p = first;
		first = first->next;
		val = p->data;
		delete p;
	}
	else 
	{
		p = first;
		for(int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		val = p->data;
		delete p;
	}
	return val;
}

int main()
{
	int A[] = {1,2,3,4,5};
	LinkedList l(A,5);
	
	cout << "Deleted: " << l.Delete(1) << endl;
	cout << "Length: " << l.Length() << endl;
	l.Insert(1,10);
	l.Display();
	
	return 0;
}
