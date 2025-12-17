#include <iostream>
#include <memory>
using std::shared_ptr;

template <class T> class Stog {
public:
  Stog();
  bool dodaj(T item);
  bool skini(T &item);
};

template <typename T> class BStablo {
public:
  BStablo() : korijen(nullptr) {}
  void unos(const T &elem);
  bool odrediPut(Stog<T> &put, const T &el) {
    shared_ptr<Cvor> curr = korijen;
    Stog<T> reversedPath;
    bool isFound = false;
    while (curr != nullptr) {
      reversedPath.dodaj(curr->elem);
      if (curr->elem == el) {
        isFound = true;
        break;
      } else if (curr->elem > el) {
        curr = curr->lijevo;
      } else {
        curr = curr->desno;
      }
    }

    T val;
    while (isFound && reversedPath.skini(val)) {
      put.dodaj(val);
    }

    return isFound;
  }

protected:
  struct Cvor {
    T elem;
    shared_ptr<Cvor> lijevo, desno;
    Cvor(const T &novi) : elem(novi), lijevo(nullptr), desno(nullptr) {};
  };
  shared_ptr<Cvor> korijen;
};

int main(void) {
  BStablo<int> stablo;
  stablo.unos(-3);
  stablo.unos(1);
  stablo.unos(2);
  stablo.unos(4);
  stablo.unos(5);
  stablo.unos(8);
  stablo.unos(10);
  Stog<int> stack;
  if (stablo.odrediPut(stack, 1)) {
    int val;
    while (stack.skini(val)) {
      std::cout << val << " ";
    }

    std::cout << std::endl;
  } else {
    std::cout << "Element nije u stablu!" << std::endl;
  };
}
