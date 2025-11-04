template <typename T> class Queue {
private:
  // privatne članske varijable koje se ne smiju
  // koristiti/mijenjati
public:
  bool enqueue(T val) {
    // Dodavanje u red. Vraća true ako je
    // dodavanje uspjelo, a false inače
  }
  bool dequeue(T &val) {
    // Skidanje iz reda. Vraća true ako je skidanje
    // uspjelo, a false inače
  }
};

template <class T> void moveLastKToFront(Queue<T> *q, int k) {
  Queue<T> tmp;
  T *val;
  int n = 0;

  while (q->dequeue(val)) {
    tmp.enqueue(*val);
    n++;
  }

  while (tmp.dequeue(val)) {
    q->enqueue(*val);
  }

  k %= n;
  int rotacija = k - n; // n = 5, k = 2, rotacija = 3
  for (int i = 0; i < rotacija; i++) {
    q->dequeue(val);
    q->enqueue(val);
  }
};

int main(void) { return 0; }
