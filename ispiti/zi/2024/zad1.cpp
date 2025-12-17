#include <iostream>
#include <memory>
using std::shared_ptr;

template <typename T> class BStablo {
public:
  BStablo() : korijen(nullptr) {};
  void unos(const T &elem) {};
  bool jesuPotomci(const T &a, const T &b, const T &c) {
    shared_ptr<Cvor> potomak;
    if (!find(korijen, c, potomak)) {
      return false;
    }

    return jePotomak(potomak, a) && jePotomak(potomak, b);
  }
  bool find(const T &a) {}

protected:
  struct Cvor {
    T elem;
    shared_ptr<Cvor> lijevo, desno;
    Cvor(const T &novi) : elem(novi), lijevo(nullptr), desno(nullptr) {};
  };
  shared_ptr<Cvor> korijen;
  bool find(shared_ptr<Cvor> node, const T &a, shared_ptr<Cvor> &elem) {
    if (node == nullptr) {
      return false;
    }

    if (node->elem == a) {
      elem = node;
      return true;
    }

    if (node->elem > a) {
      return find(node->lijevo, a, elem);
    }

    return find(node->desno, a, elem);
  };

  bool jePotomak(shared_ptr<Cvor> node, const T &a) {
    shared_ptr<Cvor> dummy;

    return find(node, a, dummy);
  }
};

int main(void) {
  BStablo<int> stablo = BStablo<int>();
  std::cout << stablo.jesuPotomci(3, 9, 7) << std::endl;
}
