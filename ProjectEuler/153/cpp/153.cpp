#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MAXN 100000000
#define LIMIT 10000

int main() {
  ll ans = 0;
  for (int i = 1; i <= LIMIT; i++) {
    ans += MAXN / i * i;
  }
  for (int k = LIMIT - 1; k >= 1; k--) {
    int start = MAXN / (k + 1) + 1;
    int end = MAXN / k;
    int len = end - start + 1;
    ans += 1LL * k * (1LL * (start - 1) * len + (1LL * len * len + len) / 2);
  }

  int a = 0;
  int b = 1;
  int c = 1;
  int d = LIMIT;
  while (c <= LIMIT) {
    int k = (LIMIT + b) / d;
    int next_c = k * c - a;
    int next_d = k * d - b;
    a = c;
    b = d;
    c = next_c;
    d = next_d;
    if (a == 0)
      continue;
    ll divisor = 1LL * a * a + 1LL * b * b;
    if (divisor > MAXN)
      continue;
    ll val = 2 * a + (a != b) * 2 * b;
    for (int multiplier = 1; multiplier * divisor <= MAXN; multiplier++) {
      ans += MAXN / (divisor * multiplier) * val * multiplier;
    }
  }

  cout << ans << '\n';
  return 0;
}