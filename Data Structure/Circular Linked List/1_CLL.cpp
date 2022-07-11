#include <iostream>
using namespace std;

/*
 * Circular Linked List:
 * A linked list in which the last node point to first node. In other word, 
 * circularly connected nodes are called linked list.
 * 
 * Uses: If we want to linear access and also want to circular access.
 * 
 */
 
struct Node
{
int data;
Node *next;
} *Head;





// Creating CLL
void create(int arr[], int n)
{
    struct Node *temp, *last;
    Head = new Node; // creating first node
    Head->data = arr[0];
    Head->next = Head; // Head node point on Head itself, so it is circular now, there is one single node
    last = Head;
    
    // Rest of the nodes
    for(int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}





// Display CLL using iterative method:
void Display(Node* h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while(h != Head);
}





// Display CLL using recursive method:
void RDisplay(Node *h)
{
    /* 
     * static variable is similar as global variable but it limited to a function.
     * This is accessible only inside a function.
     */
    static int flag = 0;
    if(h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}




// Length function for counting the length of the CLL
int Length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while(p != Head);
    return len;
}




// Recursive Length function for finding elngth of the LL
int RLength(Node *p)
{
    if(p != Head)
        return RLength(p->next)+1; // Returning time
    else
        return 0;
}




// If we insert after head, time complexity O(1) otherwise O(N)
void Insert(Node *p, int index, int x)
{
    Node *temp;
    
    // checking index is valid or not
    if(index < 0 || index > Length(Head))
        return;
    if(index == 0) // insert before Head node
    {
        temp = new Node;
        temp->data = x;
        if(Head == NULL) // check if Head is NULL then create first head node
        {
            Head = temp;
            Head->next = Head;
        }
        else
        {
            while(p->next != Head)
                p = p->next;
            p->next = temp;
            temp->next = Head;
            Head = temp;
        }
    }
    else // insert at any index
    {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        temp = new Node;
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
    }
}





// Delete CLL: If deleting 2nd node TC: O(1) otherwise O(N)
int Delete(Node *p, int index)
{
    Node *q;
    int x;
    
    if(index < 0 || index > Length(Head))
        return -1;
    
    if(index == 1) // deleting head node
    {
        while(p->next != Head)
            p = p->next;
        x = Head->data;
        if(Head == p) // is it a last node
        {
            delete Head;
            Head = NULL;
        }
        else // otherwise delete head node and make some new node, next node as a head node
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        delete q;
    }
    return x;
}




int main()
{
    int arr[] = {0, 2, 4, 6, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size);
    // Display(Head);
    RDisplay(Head);
    cout << endl << RLength(Head) << endl;
    Insert(Head, 0, 20);
    Delete(Head, 2);
    Display(Head);

    return 0;
}
