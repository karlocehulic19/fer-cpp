#include <iostream>
#include <string.h>

using namespace std;

class Point {
public:
  int x;
  int y;
};

int main(void) {
  Point p, r, s;
  cout << p.x << " " << p.y << endl;
  p.x = 10;
  p.y = 20;
  r = p;
  p.x = 120;
  cout << p.x << " " << p.y << endl;
  cout << r.x << " " << r.y << endl;
  memcpy(&s, &p, sizeof(p));
  p.x = 74;
  cout << s.x << " " << s.y << endl;
  cout << p.x << " " << p.y << endl;
  return 0;
}
