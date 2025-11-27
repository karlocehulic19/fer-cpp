bool jestPodskup(int A[], int B[], int m, int n) {
  if (n == 0) {
    return true;
  }

  if (m == 0) {
    return false;
  }

  if (A[0] == B[0])
    return jestPodskup(&A[1], &B[1], m - 1, n - 1);

  return jestPodskup(&A[1], B, m - 1, n);
}
