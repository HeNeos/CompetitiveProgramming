#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, k, a_1, a_k;
    cin >> m >> k >> a_1 >> a_k;
    // m = x + y*k -> y = m/k, x = m%k
    // y = m/k - constant
    // x = m%k + k*constant
    // MIN max(0, (m/k-C)-a_k) + max(0, (m%k+k*C)-a_1)
    // MIN max(0, m/k-a_k-C) + max(0, m%k-a_1+k*C)
    // p1 = m/k-a_k, p2 = m%k-a_1
    // MIN max(0, p1-C) + max(0, p2+k*C)
    // MAX C / m%k-a_1+k*C <= 0 -> C <= (a_1-m%k)/k -> C = max(0, (a_1-m%k)/k)
    int c = max(0, (a_1 - m % k) / k);
    ll ans =
        max(0LL, 1LL * m / k - a_k - c) + max(0LL, m % k - a_1 + 1LL * k * c);
    cout << ans << '\n';
  }
  return 0;
}
