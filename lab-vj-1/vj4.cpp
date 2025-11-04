#include "iostream"

template <typename T> class Stack {
private:
  // privatne članske varijable koje se ne smiju
  // koristiti/mijenjati
public:
  bool push(T val) {
    // Dodavanje na stog.Vraća true ako je
    // dodavanje uspjelo, a false inače
  }
  bool pop(T &val) {
    // Skidanje sa stoga. Vraća true ako je skidanje
    // uspjelo, a false inače
  }
};

template <class T> bool stacksOppositeEqual(Stack<T> *a, Stack<T> *b) {
  Stack<T> reversedA;
  T *lastPoppedA;
  while (a->pop(lastPoppedA)) {
    reversedA.push(*lastPoppedA);
  }
  Stack<T> tempReversedB;
  T *lastPoppedB;
  bool isOppositeEqual = true;
  while (reversedA.pop(lastPoppedA)) {
    // make sure a stays intact
    a->push(*lastPoppedA);

    // checks for inequalty
    if (b->pop(lastPoppedB)) {
      tempReversedB.push(*lastPoppedB);

      if (*lastPoppedA != *lastPoppedB) {
        isOppositeEqual = false;
      }
    } else {
      isOppositeEqual = false;
    }
  }
  while (tempReversedB.pop(lastPoppedB)) {
    b->push(*lastPoppedB);
  }
  return isOppositeEqual;
};

int main(void) { return 0; }
