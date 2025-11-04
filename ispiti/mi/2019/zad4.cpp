#include <iostream>

template <class T> class Queue {
private:
  struct Node {
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
  };
  Node *front;
  Node *rear;

public:
  Queue() : front(nullptr), rear(nullptr) {}

  bool enqueue(T data);
  bool dequeue(T &data);
};

// Enqueue: adds an element to the end of the queue
template <class T> bool Queue<T>::enqueue(T data) {
  Node *newNode = new (std::nothrow) Node(data);
  if (!newNode)
    return false; // memory allocation failed

  if (rear == nullptr) { // empty queue
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  return true;
}

// Dequeue: removes an element from the front of the queue
template <class T> bool Queue<T>::dequeue(T &data) {
  if (front == nullptr)
    return false; // empty queue

  Node *temp = front;
  data = front->data;
  front = front->next;

  if (front == nullptr)
    rear = nullptr; // queue became empty
  delete temp;
  return true;
}

template <class T> Queue<T> *split(Queue<T> *q) {
  T lastElement = new T();
  Queue processedQueue = new Queue<T>();
  Queue<T> *newQueue = new Queue<T>();
  int counter = 1;
  while (q->dequeue(lastElement)) {
    if (counter % 2 == 1) {
      newQueue->enqueue(lastElement);
    } else {
      processedQueue.enqueue(lastElement);
    }
    counter++;
  }

  *q = processedQueue;
  return newQueue;
}
