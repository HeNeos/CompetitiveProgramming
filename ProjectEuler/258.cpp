#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128;
using namespace std;
#define N 2000
#define MOD 20092010
#define MAX_N 1000000000000000000

typedef vector<vector<ll>> Matrix;

Matrix f(N, vector<ll>(N));

Matrix ones(int n) {
  Matrix r(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
    r[i][i] = 1;
  return r;
}

Matrix operator*(Matrix &a, Matrix &b) {
  int n = a.size(), m = b[0].size(), z = a[0].size();
  Matrix r(n, vector<ll>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < z; k++)
        r[i][j] += a[i][k] * b[k][j], r[i][j] %= MOD;
  return r;
}

Matrix multiply(Matrix &a, Matrix &b) {
  int n = a.size(), m = b[0].size(), z = a[0].size();
  Matrix r(n, vector<ll>(m));
  for (int j = 0; j < m; j++)
    for (int k = 0; k < z; k++)
      r[0][j] += a[0][k] * b[k][j], r[0][j] %= MOD;
  for (int i = 1; i < n; i++) {
    r[i][0] = r[i - 1][m - 1];
    for (int j = 1; j < m - 1; j++)
      r[i][j] = r[i - 1][j - 1];
    for (int k = 0; k < z; k++)
      r[i][m - 1] += a[i][k] * b[k][m - 1], r[i][m - 1] %= MOD;
  }
  return r;
}

Matrix fastexp(Matrix b, ll e) {
  Matrix r = ones(b.size());
  if (e == 0)
    return r;
  if (e == 1)
    return b;
  Matrix half_exp = fastexp(b, e / 2);
  Matrix ans = multiply(half_exp, half_exp);
  if (e % 2 == 1)
    ans = multiply(b, ans);
  return ans;
}

Matrix be(Matrix b, ll e) {
  if (e == 1)
    return b;
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
  Matrix g(N, vector<ll>(N, 0));
  g[0][N - 2] = 1;
  g[0][N - 1] = 1;
  for (int i = 1; i < N; i++)
    g[i][i - 1] = 1;
  Matrix f(N, vector<ll>(1, 1));
  Matrix G = fastexp(g, MAX_N - (N - 1));
  G = G * f;
  cout << G[0][0] << '\n';
  return 0;
}