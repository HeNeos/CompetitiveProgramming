#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

unordered_map<ll, ll> dp[8];

ll A(int m, ll n) {
  if (m == 0)
    return n + 1;
  if (m == 1)
    return n + 2;
  if (m == 2)
    return 2 * n + 3;
  if (m == 3)
    return (1LL << (n + 3)) - 3;
  if (dp[m].find(n) != dp[m].end())
    return dp[m][n];
  cout << m << " " << (long long)(n) << '\n';

  ll ans = 0;
  if (n == 0 and m > 0)
    ans = A(m - 1, 1);
  if (m > 0 and n > 0)
    ans = A(m - 1, A(m, n - 1));
  dp[m][n] = ans;
  return ans;
}

int main() {
  ll ans = 0;
  for (int i = 0; i <= 6; i++) {
    // cout << i << " " << A(i, i) << '\n';
    ans += A(i, i);
  }
  cout << (long long)(ans) << '\n';
  return 0;
}