
template <typename X> class ListElement {
public:
  X el;
  ListElement<X> *next;
};

template <typename T> class List {
private:
  ListElement<T> *head = nullptr;
  ListElement<T> *tail = nullptr;

public:
  bool RemoveFirst() {
    if (head == nullptr) {
      return false;
    }

    ListElement<T> *newHead = head->next;
    delete head;
    head = newHead;
    if (head == nullptr) {
      tail = nullptr;
    }
  }
};

template <typename T> bool RemoveAllFromList(List<T> *lista) {
  bool isEmpty = true;
  while (lista->RemoveFirst()) {
    isEmpty = false;
  }

  return isEmpty;
}
