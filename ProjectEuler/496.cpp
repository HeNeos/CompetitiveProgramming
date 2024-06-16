#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1000000000

// b*(b+c) = a^2
// a^2 = b^2 + bc -> b < a < b+c
// 0 < a-b < c
// a+b>c -> a^2 < ab+2b^2
// a^2+b^2+2ab < 3ab+3b^2 -> (a+b)<3b -> b<a<2b -> c<3b, 3a/2<c<3a
// b = (m-c)/2 -> m^2=(2a)^2+c^2 -> generate triplets
// u^2+v^2 = m < 2a+c
// 5/2 a < m < sqrt(13) a
int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = N;
  n = min(n, N);
  ll ans = 0;
  for (int u = 1; 1LL * u * u < 3.61 * n; u++) {
    for (int v = 1; v < u && 1LL * u * v <= n; v++) {
      if (1LL * u * u + 1LL * v * v > 3.61 * n)
        break;
      if (__gcd(u, v) == 1 and (u % 2 == 0 or v % 2 == 0)) {
        ll m = 1LL * u * u + 1LL * v * v;
        ll double_a = 2LL * u * v;
        ll c = 1LL * u * u - 1LL * v * v;
        if (c > double_a)
          swap(c, double_a);
        if (double_a % 2 != 0) {
          m *= 2;
          c *= 2;
          double_a *= 2;
        }
        if (5 * c >= 3 * m or double_a > 2 * n)
          continue;
        int a = double_a / 2;
        int b = (m - c) / 2;
        int cnt = n / a;
        ans += (1LL * (cnt + 1) * cnt / 2) * a;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}