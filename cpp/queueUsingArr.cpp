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
	int rear = -1;
	int front = -1;
	Q = new int [size];
}

Queue::~Queue() {
	delete [] Q;
}

bool Queue::isFull(){
	if(rear == size-1) {
		return true;
	}
	return false;
}

bool Queue::isEmpty() {
	if(front == rear) {
		return true;
	}
	return false;
}

void Queue::enqueue(int x) {
	if(isFull()) {
		cout << "Queue Overflow" << endl;
	}
	else{
		rear++;
		Q[rear] = x;
	}
}

int Queue::dequeue() {
	int x = -1;
	if(isEmpty()) {
		cout << "Queue underflow" << endl;
	}
	else{
		front++;
		x = Q[front];
	}
	return x;
}

void Queue::display() {
	for(int i=front+1; i<=rear; i++){
		cout << Q[i] << flush;
		if(i < rear) {
			cout << " <- " << flush;
		}
	}
	cout << endl;
}

int main(void) {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	Queue q(sizeof(a)/sizeof(a[0]));

	for(int i=0; i < (sizeof(a)/sizeof(a[0])); i++){
		q.enqueue(a[i]);
	}

	q.display();

	q.enqueue(8);

	return 0;
}

// #include <iostream>

// using namespace std;
 
// class Queue{
// private:
//     int size;
//     int front;
//     int rear;
//     int* Q;
// public:
//     Queue(int size);
//     ~Queue();
//     bool isFull();
//     bool isEmpty();
//     void enqueue(int x);
//     int dequeue();
//     void display();
// };
 
// Queue::Queue(int size) {
//     this->size = size;
//     front = -1;
//     rear = -1;
//     Q = new int [size];
// }
 
// Queue::~Queue() {
//     delete [] Q;
// }
 
// bool Queue::isEmpty() {
//     if (front == rear){
//         return true;
//     }
//     return false;
// }
 
// bool Queue::isFull() {
//     if (rear == size-1){
//         return true;
//     }
//     return false;
// }
 
// void Queue::enqueue(int x) {
//     if (isFull()){
//         cout << "Queue Overflow" << endl;
//     } else {
//         rear++;
//         Q[rear] = x;
//     }
// }
 
// int Queue::dequeue() {
//     int x = -1;
//     if (isEmpty()){
//         cout << "Queue Underflow" << endl;
//     } else {
//         front++;
//         x = Q[front];
//     }
//     return x;
// }
 
// void Queue::display() {
//     for (int i=front+1; i<=rear; i++){
//         cout << Q[i] << flush;
//         if (i < rear){
//             cout << " <- " << flush;
//         }
//     }
//     cout << endl;
// }
 
// int main() {
 
//     int A[] = {1, 3, 5, 7, 9};
 
//     Queue q(sizeof(A)/sizeof(A[0]));
 
//     // Enqueue
//     for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
//         q.enqueue(A[i]);
//     }
 
//     // Display
//     q.display();
 
//     // Overflow
//     q.enqueue(10);
 
//     // Dequeue
//     for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
//         q.dequeue();
//     }
 
//     // Underflow
//     q.dequeue();
    
//     return 0;
// }