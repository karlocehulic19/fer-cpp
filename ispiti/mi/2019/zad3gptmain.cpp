#include <iostream>
using namespace std;

template <typename T> struct ListElement {
  T data;
  ListElement<T> *next;
};

template <typename T> class List {
  ListElement<T> *head = nullptr;

public:
  void push_back(T value) {
    ListElement<T> *newElem = new ListElement<T>{value, nullptr};
    if (!head) {
      head = newElem;
    } else {
      ListElement<T> *temp = head;
      while (temp->next)
        temp = temp->next;
      temp->next = newElem;
    }
  }

  void print() const {
    ListElement<T> *temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void removeGreaterThan(T item) {
    ListElement<T> *dummy = new ListElement<T>{-1, nullptr};
    dummy->next = head;
    ListElement<T> *curr = dummy;
    ListElement<T> *toCheck = dummy->next;
    while (toCheck) {
      if (toCheck->data <= item) {
        curr->next = toCheck;
        curr = toCheck;
      }

      toCheck = toCheck->next;
    }
  }
};

int main() {
  List<int> lista;

  // Dodajemo nekoliko elemenata
  lista.push_back(3);
  lista.push_back(7);
  lista.push_back(2);
  lista.push_back(9);
  lista.push_back(5);
  lista.push_back(1);

  cout << "Pocetna lista: ";
  lista.print();

  int item = 4;
  cout << "Uklanjam sve elemente vece od " << item << "..." << endl;

  lista.removeGreaterThan(item);

  cout << "Lista nakon uklanjanja: ";
  lista.print();

  return 0;
}
