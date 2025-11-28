template <class T> class List {
private:
  struct Atom {
    T data;
    Atom *next;
  };
  Atom *head = nullptr;

public:
  bool insert(T data); // dod. na početak
  void kopirajParne(List<T> &dstList) {
    Atom dummy;
    Atom *srcCurr = head;
    Atom *dstCurr = &dummy;
    dstCurr->next = dstList.head;

    while (srcCurr != nullptr) {
      if (srcCurr->data % 2 == 0) {
        Atom *newNode = new Atom();
        newNode->next = nullptr;
        newNode->data = srcCurr->data;
        dstCurr->next = newNode;
        dstCurr = newNode;
      }

      srcCurr = srcCurr->next;
    }

    dstList.head = dummy->next;
  }
};
