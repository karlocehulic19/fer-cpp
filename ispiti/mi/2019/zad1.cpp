#include <iostream>
#include <string>

using namespace std;

bool podnizUNizu(string niz, string podniz, int pocetak) {
  if (podniz[0] == '\0')
    return true;
  if (podniz[0] != niz[pocetak])
    return false;
  return podnizUNizu(niz, podniz.substr(1), pocetak + 1);
}

bool podnizUNizu1(string niz, string podniz, int pocetak) {
  if (podniz[0] == '\0')
    return true;
  else if (niz[pocetak] == podniz[0]) {
    return podnizUNizu1(niz, podniz.substr(1), pocetak + 1);
  } else
    return false;
}

int main() {
  string niz = "Dobar dan!", podniz = "dan";
  cout << podnizUNizu(niz, podniz, 4) << endl;

  return 0;
}
