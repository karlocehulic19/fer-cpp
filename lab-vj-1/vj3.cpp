#include <iostream>

template <typename T> class ListElement {
public:
  T data;
  ListElement<T> *next;
};

template <typename T> class List {
private:
  ListElement<T> *head;

public:
  List() : head(nullptr) {}
  void mergeSorted(List<T> *other) {
    ListElement<T> dummy;
    ListElement<T> curr;
    ListElement<T> first = head;
    ListElement<T> second = *other;
    curr = dummy;

    while (first != nullptr && second != nullptr) {
      if (first == nullptr || second.data < first.data) {
        curr.next = second;
        second = second.next;
      } else {
        curr.next = first;
        first = first.next;
      }
    }

    head = dummy.next;
  };
};

int main(void) { return 0; }
