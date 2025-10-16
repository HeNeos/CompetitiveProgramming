#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;

#define MOD 1000000007

typedef vector<vl> Matrix;
Matrix ones(int n) {
  Matrix r(n, vl(n));
  for (int i = 0; i < n; i++)
    r[i][i] = 1;
  return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
  int n = a.size(), m = b[0].size(), z = a[0].size();
  Matrix r(n, vl(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < z; k++)
        r[i][j] += a[i][k] * b[k][j], r[i][j] %= MOD;
  return r;
}
Matrix be(Matrix b, ll e) {
  Matrix r = ones(b.size());
  while (e) {
    if (e & 1LL)
      r = r * b;
    b = b * b;
    e >>= 1;
  }
  return r;
}

Matrix build_transition_matrix(int k) {
  Matrix transition_matrix(k, vector<ll>(k));
  transition_matrix[0][0] = 1;
  transition_matrix[0][k - 2] = 1;
  transition_matrix[0][k - 1] = 1;
  transition_matrix[k - 1][k - 1] = 1;
  for (int i = 1; i < k - 1; i++) {
    transition_matrix[i][i - 1] = 1;
  }
  return transition_matrix;
}

Matrix build_initial_matrix(int k) {
  Matrix initial_matrix(k, vector<ll>(1));
  initial_matrix[0][0] = 1;
  initial_matrix[k - 1][0] = 1;
  return initial_matrix;
}

int main() {
  int t;
  cin >> t;
  vector<Matrix> transition_matrices(3);
  vector<Matrix> initial_matrices(3);
  for (int k = 3; k <= 5; k++) {
    transition_matrices[k - 3] = build_transition_matrix(k);
    initial_matrices[k - 3] = build_initial_matrix(k);
  }
  while (t--) {
    ll n;
    cin >> n;
    if (n <= 3) {
      ll ans = n * n - n;
      cout << ans / 2 << '\n';
      continue;
    }
    ll s = 0;
    for (int k = 3; k <= 5; k++) {
      Matrix f = be(transition_matrices[k - 3], n - k + 1);
      f = f * initial_matrices[k - 3];
      s += f[0][0];
      s %= MOD;
    }
    cout << s << '\n';
  }
  return 0;
}
