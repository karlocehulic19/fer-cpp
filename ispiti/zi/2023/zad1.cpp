#include <iostream>
#include <memory>

using std::shared_ptr;
template <typename T> class BStablo {
public:
  BStablo() : korijen(nullptr) {}
  void unos(const T &elem);
  int brojPuteva(T elem) { return brojPuteva(korijen, elem); }

protected:
  struct Cvor {
    T elem;
    shared_ptr<Cvor> lijevo, desno;
    Cvor(const T &novi) : elem(novi), lijevo(nullptr), desno(nullptr) {}
  };
  shared_ptr<Cvor> korijen;

  int brojPuteva(shared_ptr<Cvor> node, const T &elem) {
    if (node == nullptr || node->elem >= elem)
      return 0;
    bool isLeaf = node->lijevo == nullptr && node->desno == nullptr;
    if (isLeaf)
      return 1;

    return brojPuteva(node->lijevo, elem) + brojPuteva(node->desno, elem);
  }
};

int main(void) {
  BStablo<int> stablo;
  stablo.unos(1);
  stablo.unos(2);
  stablo.unos(3);
  stablo.unos(4);
  stablo.unos(5);
  stablo.unos(6);
  stablo.unos(7);

  std::cout << stablo.brojPuteva(12) << std::endl;
}

// O(n) for worst case, O(1) for the best case, we can't detirmine the average
