#include <iostream>

using namespace std;

template <typename T> class ListElement {
public:
  T i;
  ListElement<T> *next;
};

template <typename T> class MyList {
private:
  ListElement<T> *head;

public:
  MyList() { this->head = nullptr; };

  void AddUnique(T val) {
    if (this->Contains(val)) {
      return;
    }

    ListElement<T> *dummy = new ListElement<T>();
    dummy->next = head;

    ListElement<T> *curr = dummy;

    while (curr->next != nullptr) {
      curr = curr->next;
    }

    ListElement<T> *newUnique = new ListElement<T>;
    newUnique->i = val;
    curr->next = newUnique;

    head = dummy->next;
  }

  void Remove(T val) {
    ListElement<T> *dummy = new ListElement<T>();
    dummy->next = head;

    ListElement<T> *curr = dummy;

    while (curr->next != nullptr) {
      ListElement<T> *nextPtr = curr->next;
      if (nextPtr->i == val) {
        curr->next = nextPtr->next;
        delete nextPtr;
        break;
      }

      curr = nextPtr;
    }

    head = dummy->next; // in case head is delted
  }

  bool Contains(T val) {
    ListElement<T> *curr = head;

    while (curr != nullptr) {
      if (curr->i == val) {
        return true;
      }
      curr = curr->next;
    }

    return false;
  }
};

int main(void) {
  MyList<int> list;
  cout << "List add 6" << endl;
  list.AddUnique(6);
  cout << "List contains 6: " << list.Contains(6) << endl;
  cout << "List contains 7: " << list.Contains(7) << endl;
  cout << "List remove 6" << endl;
  list.Remove(6);
  cout << "List contains 6: " << list.Contains(6) << endl;
  cout << "List add 7 twice" << endl;
  list.AddUnique(7);
  list.AddUnique(7);
  cout << "List contains 7: " << list.Contains(7) << endl;
  cout << "List remove 7 once" << endl;
  list.Remove(7);
  cout << "List contains 7: " << list.Contains(7) << endl;

  return 0;
}
