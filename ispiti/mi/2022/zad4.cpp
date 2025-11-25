template <typename T> class Queue {
private:
  // privatne članske varijable koje se ne smiju
  // koristiti/mijenjati
public:
  bool enqueue(T val) {
    // Dodavanje u red. Vraća true ako je dodavanje
    // uspjelo, a false inače
  }
  bool dequeue(T &val) {
    // Skidanje iz reda. Vraća true ako je skidanje
    // uspjelo, a false inače
  }
};

template <typename T>
void split(Queue<T> *sourceq, Queue<T> *queue1, Queue<T> *queue2) {
  T even;
  if (!sourceq->dequeue(even)) {
    return;
  }
  queue1->enqueue(even);

  T odd;
  if (!sourceq->dequeue(odd)) {
    return;
  }
  queue2->enqueue(odd);

  split(sourceq, queue1, queue2);
};

// their solution, pretty neet, not sure if easier to understand?
template <typename T>
void splitTheir(Queue<T> *sourceq, Queue<T> *queue1, Queue<T> *queue2) {
  T val;
  if (sourceq->dequeue(val)) {
    queue1->enqueue(val);
    splitTheir(sourceq, queue2, queue1);
  }
}
