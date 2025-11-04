#include <iostream>

using namespace std;

void reverse(char *s, int l, int r) {
  if (l >= r)
    return;

  char tmp = s[l];
  s[l] = s[r];
  s[r] = tmp;

  reverse(s, l + 1, r - 1);
}

int main() {
  char a[] = "abcdef";
  reverse(a, 1, 4);
  cout << a << endl;
  return 0;
}
