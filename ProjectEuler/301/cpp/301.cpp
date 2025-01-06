#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN (1 << 30)

int n;
ll solve(ll current = 0) {
  if (current == 0 or current > MAXN)
    return 0;
  ll ans = 0;
  int last_bit = (current & 1);
  if (last_bit == 0) {
    ans += solve(current * 2 + 1);
  }
  ans += solve(current * 2);
  if (current <= MAXN)
    ans++;
  return ans;
}

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = MAXN;
  n = min(n, MAXN);
  ll ans = solve(1);
  cout << ans << '\n';
  return 0;
}