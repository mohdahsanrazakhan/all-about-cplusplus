/*
 * Implementation using array
*/

#include<iostream>
using namespace std;

class Queue {
private:
	int size;
	int front;
	int rear;
	int* Q;
public:
	Queue(int size);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enqueue(int x);
	int dequeue();
	void display();
};

Queue::Queue(int size) {
	this->size = size;
	front = -1;
	rear = -1;
	Q = new int[size];
}

Queue::~Queue() {
	delete[] Q;
}

bool Queue::isEmpty() {
	if(front == rear) {
		return true;
	}
	return false;
}

bool Queue::isFull() {
	if( rear == size-1) {
		return true;
	}
	return false;
}

void Queue::enqueue(int x) {
	if(isFull()) {
		cout << "Queue Overflow!" << endl;
	}
	else {
		rear++;
		Q[rear] = x;
	}
}

int Queue::dequeue() {
	int x = -1; 
	if(isEmpty()) {
		cout << "Queue Underflow" << endl;
	}
	else {
		front++;
		x = Q[front];
	}
	return x;
}

void Queue::display() {
	for(int i = front + 1; i <= rear; i++) {
		cout << Q[i] << flush;
		if(i < rear) {
			cout << " <- " << flush;
		}
	}
	cout << endl;
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	
	Queue q(sz);
	
	// Enqueue
	for(int i = 0; i < sz; i++) {
		q.enqueue(arr[i]);
	}
	
	// Display
	q.display();
	
	// Overflow
	q.enqueue(10);
	
	// Dequeue
	for(int i = 0; i < sz; i++) {
		q.dequeue();
	}
	
	// Underflow
	q.dequeue();
	
	return 0;
}

