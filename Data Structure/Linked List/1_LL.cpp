#include <iostream>
using namespace std;

struct Node
{
    int data;          // data member
    struct Node *next; // Self-referential pointer.
    // Structre which includes at least one member that is a pointer to the structure of its own kind.
} *first = NULL; // global pointer (initialize with NULL)

// Create function for LL
void create(int arr[], int size)
{
    struct Node *temp, *last;
    first = new Node; // To create first node in heap memory
    /*
     * To use below script we can include<stdlib.h>
     * first = (struct Node *)malloc(sizeof(struct Node));
     * Above syntax is use in C but it is too lengthy so, I cannot use this syntax in this documentary.
     * I'll use C++ syntax to create new Node. using 'new'
     */
    first->data = arr[0]; // To access members of a structure through a pointer, use arrow operator.
    // To access members of a structure, use dot operator
    first->next = NULL; // first doesn't have any next node so NULL
    last = first;       // last also point to first

    for (int i = 1; i < size; i++)
    {
        temp = new Node;     // Create a new node form temp
        temp->data = arr[i]; // temp var contain data
        temp->next = NULL;   // temp next NULL
        last->next = temp;   // last next point to temp
        last = temp;         // last on temp
    }
}

// Display function using loops (iterative)
void Display(struct Node *p) // 'p' is pointing to the first node
{
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Display function using recursive
void RDisplay(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " "; // calling time
        RDisplay(p->next);
        // cout << p->data << " "; // returning time
    }
}

// Count function for finding length of the LL
int Count(struct Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Recursive Count function for finding length of the LL
int RCount(struct Node *p)
{
    if (p != NULL)
        return RCount(p->next) + 1; // Returning time
    else
        return 0;
}

// Sum all the data of LL
int Sum(Node *p)
{
    int add = 0;
    while (p != NULL)
    {
        add += p->data;
        p = p->next;
    }
    return add;
}

// Recursive Sum function for adding all the data of LL
int RSum(Node *p)
{
    if (p != NULL)
        return RSum(p->next) + p->data; // Returning time
    return 0;
}

// Max() function for find the maximum value in LL
int Max(Node *p)
{
    int max = INT32_MIN; // INT32_MIN specifies that an integer variable cannot store any value below this limit.

    while (p) // means p is not equal to NULL
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// Recursive Max function for finding maximum value in LL
int RMax(Node *p)
{
    int max = 0;
    if (p == 0) // p is NULL, or p is empty
        return INT32_MIN;
    max = RMax(p->next); // max can store data of next address
    if (max > p->data)   // comparing next address data (max) to current data (p->data)
        return max;
    else
        return p->data;
}

// Max function using Ternary Condition
int TMax(Node *p)
{
    int max = 0;
    if (p == 0)
        return INT32_MIN;
    max = TMax(p->next);
    return max > p->data ? max : p->data;
}

// Min() function for finding minimum value in LL
int Min(Node *p)
{
    int min = INT32_MAX; // INT32_MAX specifies that an integer variable cannot store any value above this limit.
    while (p != NULL)
    {
        if (min > p->data)
            min = p->data;
        p = p->next;
    }
    return min;
}

// Recursive min function for finding minimum value in LL
int RMin(Node *p)
{
    int min = 0;
    if (p == 0) // p is NULL
        return INT32_MAX;
    min = RMin(p->next); // min can store next address data
    if (min < p->data)
        return min;
    return p->data;
}

// Min function using Ternary Condition
int TMin(Node *p)
{
    int min = 0;
    if (p == NULL)
        return INT32_MAX;
    min = TMin(p->next);
    return min < p->data ? min : p->data;
}

/*
 * Searching a Linked List:
 * Generally there are two type of searching:
 * 1. Linear Search
 * 2. Binary Search
 *
 * Binary Search is not suitable because we cannot go directly to the middle of the element.
 * So, Linear Search is applied.
 *
 * Improve Linear Search:
 * Transposition : Interchange the key value to the previous value.
 * Move to first : Key value is move to the head.
 *
 * Transposition cannot use in linked list because we avoid movement of data, we prefer movement of node.
 * So, it is better to take out the node  and put it at front/first node.
 */

// Search() function can search a perticular key in a LL
Node *Search(Node *p, int key) // Node* is use because this function can return address of key. Also use void return type, but using Node* is good practice.
{
    while (p != NULL)
    {
        if (key == p->data)
            return p; // Return the address of 'p'
        p = p->next;
    }
}

// Recursive search function in LL
Node *RSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

// Searching LL using move to first method:
// Move to first method: Iterative way
struct Node *mofSearch(Node *p, int key) // mof stands for 'move to  first' method
{
    Node *q = NULL; // It is a follower of pointer 'p'

    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next; // q's next point to the p's next
            p->next = first;   // p's next point to the first.
            first = p;         // first point to the p's address. So, 'p' become first node
            return p;
        }
        q = p;       // q takes p's place and
        p = p->next; // p move one step forward
    }
    return NULL;
}

// Searching LL using move to first method: Recursive way
struct Node *RmofSearch(Node *p, int key) // mof stands for 'move to  first' method
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RmofSearch(p->next, key);
}

// Insert function for inserting any value in LL
void Insert(Node *p, int index, int val)
{
    struct Node *temp; // temp pointer which contain 'val'

    if (index < 0 || index > Count(p)) // If index out of the range then just return. Nothing will be printed.
        return;
    temp = new Node; // temp create new Node in the heap memory to contain 'val'
    temp->data = val;

    if (index == 0) // index at '0' means insert at first node.
    {
        temp->next = first;
        first = temp;
    }
    else // insert at any other node.
    {
        for (int i = 0; i < index - 1; i++) // Move to desire the node
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

// Insert in sorted linked list
void SortedInsert(Node *p, int val)
{
    struct Node *temp, *q = NULL; // pointer q follows pointer p

    temp = new Node;
    temp->data = val;
    temp->next = NULL;

    // If linked list is already empty
    if (first == NULL)
        first = temp;
    else
    {
        while (p && p->data < val)
        {
            q = p;
            p = p->next;
        }
        // New element going to insert at first node
        if (p == first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

// Deleting node from linked list
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL; // q follows p
    int x = -1, i;

    if (index < 1 || index > Count(p)) // index out of the range
        return -1;
    // Delete the first node
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    // Delete any other node
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// Remove Duplicate Values
void RemoveDuplicate(Node *p)
{
    struct Node *q = p->next; // 'q' points next node of 'p'
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q); // In C++ delete() is use to pointer 'q' from heap memory. In C lang use free()
            q = p->next;
        }
    }
}

// Reverse a linked list
void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = new int[Count(p)]; // Dynamic array created in heap memory.
    // A = (int *)malloc(sizeof(int)*count(p));

    while (q != NULL)
    {
        A[i] = q->data; // A[i] stores all the linked list data. Data store from first node to last node.
        q = q->next;
        i++;
    }
    q = p; // q == NULL which mean at pointing after last node
    i--;   // i is now at last node
    // Below blocks of code are reversing
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Recursive method to reverse a linked list
void Reverse3(struct Node *q, struct Node *p)
{
    if (p) // p not equal to NULL
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

// Concatenating two linked list

// Merge two linked list

// Is loop or not

int main()
{
    int arr[] = {2, 4, 5, 1, 1, 1, 1, 6, 8, 10};
    int length = sizeof(arr) / sizeof(arr[0]); // Calculate length of an array

    create(arr, length);
    Display(first); // first is a global variable that's why I can access in the main() function
    // RDisplay(first);
    cout << endl
         << Count(first);
    // cout << endl << RCount(first);
    cout << endl
         << Sum(first);
    // cout << endl << RSum(first);
    cout << endl
         << Max(first);
    // cout << endl << RMax(first);
    cout << endl
         << TMax(first);
    cout << endl
         << Min(first);
    // cout << endl << RMin(first);
    cout << endl
         << TMin(first);
    cout << endl
         << Search(first, 10);
    // cout << endl << RSearch(first, 10);
    cout << endl
         << mofSearch(first, 14);
    // cout << endl << RmofSearch(first, 14);
    Insert(first, 0, 1);
    Insert(first, 2, 2);
    Insert(first, 9, 1);
    Display(first);
    SortedInsert(first, 9);
    SortedInsert(first, 12);
    Display(first);
    Delete(first, 1);
    Delete(first, 5);
    Delete(first, 9);
    Display(first);
    RemoveDuplicate(first);
    Display(first);
    Reverse1(first);
    Display(first);
    Reverse2(first);
    Display(first);
    Reverse3(NULL, first);
    Display(first);
    return 0;
}
