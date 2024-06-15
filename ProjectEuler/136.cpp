#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 50000000

int count_solutions[N + 5];

void fill(int n) {
  for (int y = 1; y <= n; y++) {
    ll product = y;
    for (int r = (y + 3) / 4; r < y; r++) {
      product *= (4 * r - y);
      if (product > n)
        break;
      count_solutions[product]++;
      product = y;
    }
  }
}

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = N;
  n = min(n, N);
  fill(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (count_solutions[i] == 1)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}