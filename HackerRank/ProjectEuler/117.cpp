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

int main() {
  int t;
  cin >> t;
  Matrix transition_matrix(4, vector<ll>(4));
  for (int i = 0; i < 4; i++)
    transition_matrix[0][i] = 1;
  for (int i = 1; i < 4; i++)
    transition_matrix[i][i - 1] = 1;
  Matrix initial_matrix(4, vector<ll>(1));
  initial_matrix[0][0] = 4;
  initial_matrix[1][0] = 2;
  initial_matrix[2][0] = 1;
  initial_matrix[3][0] = 1;
  while (t--) {
    ll n;
    cin >> n;
    if (n <= 3) {
      ll ans = n * n - n;
      cout << ans / 2 << '\n';
      continue;
    }
    Matrix f = be(transition_matrix, n - 4);
    f = f * initial_matrix;
    ll s = f[0][0];
    cout << s << '\n';
  }
  return 0;
}
