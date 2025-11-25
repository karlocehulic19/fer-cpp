template <typename T> class ListElement {
public:
  T val;
  ListElement<T> *next;
  ListElement<T> *prev;
};

template <typename T> class DoubleList {
private:
  ListElement<T> dummy;

public:
  DoubleList() {
    dummy.next = nullptr;
    dummy.prev = nullptr;
  }

  void AddFirst(T val) {
    ListElement<T> *newFirstNode = new ListElement<T>();
    newFirstNode->prev = &dummy;
    newFirstNode->next = dummy.next;
    newFirstNode->val = val;

    ListElement<T> *prevFirstNode = dummy.next;
    if (prevFirstNode != nullptr)
      prevFirstNode->prev = newFirstNode;
    dummy.next = newFirstNode;
  } // vaš kod za AddFirst }
  bool Find(T val) {
    ListElement<T> *currNode = dummy.next;
    while (currNode != nullptr) {
      if (currNode->val == val)
        return true;
      currNode = currNode->next;
    }

    return false;
  } // vaš kod za Find }
  ~DoubleList() {
    ListElement<T> *toDelete = dummy.next;
    while (toDelete != nullptr) {
      ListElement<T> *nextToDelete = toDelete->next;
      delete toDelete;
      toDelete = nextToDelete;
    }
  }
  // vaš kod za destruktor }
};
