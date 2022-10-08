#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // global pointer

void createFirst(int A[], int size) 
{
    int i;
    Node *temp, *last;
    
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i = 1; i < size; i++) 
	{
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void createSecond(int A[], int size) 
{
    int i;
    Node *temp, *last;
    
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for(int i = 1; i < size; i++) 
	{
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void createThird(int A[], int size) 
{
    int i;
    Node *temp, *last;
    
    third = new Node;
    third->data = A[0];
    third->next = NULL;
    last = third;
    
    for(int i = 1; i < size; i++) 
	{
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(Node *p) 
{
    while(p) // means p != NULL
	{ 
        cout << p->data << " ";
        p = p->next;
    }
}

void Concat(Node *p, Node *q) 
{
    third = p;
    while(p->next != NULL) 
	{
        p = p->next;
    }
    p->next = q;
}

void Merge(Node *p, Node *q) 
{
    struct Node *last;
    if(p->data < q->data) 
	{
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else 
	{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q) // means both p != NULL && q != NULL 
    {
        if(p->data < q->data) 
		{
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else 
		{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;
}

int isLoop(Node *f)
{
    Node *p, *q;
    
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while(p && q && p != q);
    if(p == q)
        return 1;
    else
        return 0;
}

int main() 
{
    int A[] = {10,20,30,40,50};
    int B[] = {5,25,120,320,400};
    
    int sizeA = sizeof(A)/sizeof(A[0]);
    int sizeB = sizeof(B)/sizeof(B[0]);
    
    createFirst(A,sizeA);
    createSecond(B,sizeB);
    
    Concat(first, second); // O/P: 10 20 30 40 50 5 25 120 320 400 
    Merge(first, second); // O/P: 5 10 20 25 30 40 50 120 320 400 
    
    cout << isLoop(first);
    
    Display(third);
}

