template <typename T> struct ListElement {
  T data;
  ListElement<T> *next;
};

template <typename T> class List {
  ListElement<T> *head = nullptr;

public:
  void removeGreaterThan(T item) {
    ListElement dummy = new ListElement<T>();
    dummy.next = head;
    ListElement curr = dummy;
    ListElement toCheck = dummy.next;
    while (toCheck) {
      if (toCheck.data <= item) {
        curr.next = toCheck;
        curr = toCheck;
      }

      toCheck = toCheck.next;
    }
  }
};

int main() {}
