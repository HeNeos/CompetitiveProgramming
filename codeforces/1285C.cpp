#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll ans = -1;
  for (ll d = 1; d * d <= x; d++) {
    if (x % d == 0) {
      ll g = __gcd(d, x / d);
      if (g == 1) {
        if (ans == -1)
          ans = x / d;
        ans = min(ans, x / d);
      }
    }
  }
  cout << x / ans << " " << ans << '\n';
  return 0;
}