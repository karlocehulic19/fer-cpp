#include <iostream>

void ispisiVeci(int A[], int m, int B[], int n) {
  if (m == 0 and n == 0) {
    return;
  }

  if (m == n) {
    std::cout << A[m - 1] << " " << B[n - 1] << " "
              << std::max(A[m - 1], B[n - 1]) << std::endl;
    return ispisiVeci(A, m - 1, B, n - 1);
  }

  if (m > n) {
    std::cout << A[m - 1] << " - " << A[m - 1] << std::endl;
    return ispisiVeci(A, m - 1, B, n);
  }

  std::cout << "- " << B[n - 1] << " " << B[n - 1] << std::endl;
  ispisiVeci(A, m, B, n - 1);
}
