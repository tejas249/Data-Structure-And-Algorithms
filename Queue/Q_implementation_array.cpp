#include <iostream>
#include <queue>

using namespace std;

class Queue {
public:
  int size;
  int *arr;
  int front;
  int rear;

  Queue(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  // push function
  void push(int val) {
    // overflow check
    if (rear == size - 1) {
      cout << "Overflow queue" << endl;
      return;
    } else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    } else {
      arr[rear] = val;
      rear++;
    }
  }

  // pop function
  void pop() {
    // underflow check
    if (front == -1 && rear == -1) {
      cout << "Underflow queue" << endl;
    } else if (front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1;
    } else {
      arr[front] = -1;
      front++;
    }
  }

  // get size
  int getsize() {
    if (front == -1 && rear == -1) {
      return 0;
    } else {
      return (rear - front + 1);
    }
  }

  // is empty
  bool isempty() {
    if (front == -1 && rear == -1) {
      return true;
    } else {
      return false;
    }
  }

  // get front element
  int getfront() {
    if (front != -1) {
      return arr[front];
      }
    else {
      return -1;
    }
  }

  // get rear element
  int getrear() {
    if (rear == -1) {
      return -1;
   }
    else {
      return arr[rear];
    }
  }
};


int main() {
  // creating the queue
  Queue q(5); // Assuming a maximum size of 5

  // inserting the elements in the queue in the desired order
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  cout << "Size of the queue: " << q.getsize() << endl;
  cout << "Front element of the queue: " << q.getfront() << endl;
  cout << "Rear element of the queue: " << q.getrear() << endl;

  return 0;
}






