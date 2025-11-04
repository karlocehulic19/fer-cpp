#include <iostream>

using namespace std;

namespace s1 {
const int a = 1;
}

namespace s2 {
const int a = 2;
}

using namespace s1;
using namespace s2;

class Point {
public:
  double x, y;
  Point() : x(0), y(0) {}
  Point(double xin, double yin) {
    x = xin;
    y = yin;
  }

  void print() { cout << "(" << x << "," << y << ")" << endl; }
};

int main(void) {
  int arr[] = {1, 2, 3};
  cout << a;
}
