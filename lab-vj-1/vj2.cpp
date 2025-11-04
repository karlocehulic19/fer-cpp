#include <iostream>

template <typename T> class ListElement {
public:
  T data;
  ListElement<T> *next;
};

template <typename T> class List {
private:
  ListElement<T> *head;
  T sumListRec(ListElement<T> *p) {
    if (p == nullptr)
      return 0;
    return p->data + sumListRec(p->next);

  }; // rekurzivna
  // pomoćna funkcija
public:
  List() : head(nullptr) {}
  T sumList() {
    sumListRec(head);
  }; // javna funkcija koja poziva
     // pomoćnu funkciju sumListRec
};

int main(void) { return 0; }
