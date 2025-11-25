template <class T> class Stack {
public:
  Stack();
  bool push(T item);
  bool pop(T &item);
};

template <class T> class Queue {
public:
  Queue();
  bool enqueue(T data);
  bool dequeue(T &data);
};

// ovo ne zadovoljava constarin (koristi iskljuciv pomocni stog, stogove...)
template <class T> void preurediRedBezUvjeta(Queue<T> *q, T v) {
  Queue<T> smaller;
  Queue<T> other;
  T val;

  while (q->dequeue(val)) {
    if (val < v) {
      smaller.enqueue(val);
    } else {
      other.enqueue(val);
    }
  }

  T smallerVal;
  while (smaller.dequeue(smallerVal)) {
    q->enqueue(smallerVal);
  }

  T otherVal;
  while (other.dequeue(otherVal)) {
    q->enqueue(otherVal);
  }
};

template <class T> void reverseStack(Stack<T> *toReverse) {
  Stack<T> tmp;
  T val;

  while (toReverse->pop(val)) {
    tmp.push(val);
  }

  while (tmp.pop(val)) {
    toReverse->push(val);
  }
}

template <class T> void preurediRed(Queue<T> *q, T v) {
  Stack<T> smallStack, otherStack, tmp;

  T qVal;

  while (q->dequeue(qVal)) {
    if (qVal < v) {
      smallStack.push(qVal);
    } else {
      otherStack.push(qVal);
    }
  }

  // ako smijemo definirati vanjske funkcije -> DRY
  // reverseStack(&smallStack);

  T tmpVal1;
  while (smallStack.pop(tmpVal1)) {
    tmp.push(tmpVal1);
  }

  while (tmp.pop(tmpVal1)) {
    smallStack.push(tmpVal1);
  }

  T smallerVal;
  while (smallStack.pop(smallerVal)) {
    q->enqueue(smallerVal);
  }

  // ako smijemo definirati vanjske funkcije -> DRY
  // reverseStack(&otherStack);

  T tmpVal2;
  while (otherStack.pop(tmpVal2)) {
    tmp.push(tmpVal2);
  }

  while (tmp.pop(tmpVal2)) {
    otherStack.push(tmpVal2);
  }

  T otherVal;
  while (otherStack.pop(otherVal)) {
    q->enqueue(otherVal);
  }
}
