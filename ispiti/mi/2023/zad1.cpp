int zamijeniParne(int A[], int n) {
  // sto je ovaj int, jel uvijek mora biti sizeof A ili ga mozemo drugacije
  // koristiti ako je polje manje od < 4 ne radimo nista...
  int startingIndex = 0;
  int length = n;
  int change = 0;
  if (n < 2)
    return 0; // npr za [1] nemamo zamijena
  if (A[0] % 2 == 0 && A[n - 1] % 2 == 0) {
    int tmp = A[0];
    A[0] = A[n - 1];
    A[n - 1] = tmp;

    change++;
    startingIndex = 1;
    length--;
  }

  if (A[0] % 2 != 0) {
    startingIndex = 1;
  }

  if (A[n - 1] % 2 != 0) {
    length--;
  }

  return change + zamijeniParne(&A[startingIndex], length);
};

int main(void) {
  // test zamijeniParne
  int A[] = {10, 2, 5, 6, 7, 9, 1};
  int B[] = {3, 1, 10, 2, 5, 6, 7, 8, 9, 1};
  int C[] = {1, 5, 1};
  int D[] = {12};
  int AZam = zamijeniParne(A, 7);
  int BZam = zamijeniParne(B, 10);
  int CZam = zamijeniParne(C, 3);
  int DZam = zamijeniParne(D, 1);

  return 0;
}
