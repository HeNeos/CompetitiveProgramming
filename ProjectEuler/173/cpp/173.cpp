#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 1000000

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = MAXN;
  n = min(n, MAXN);
  ll ans = 0;
  for (int i = 3; i <= (n + 4) / 4; i++) {
    ll sq = 1LL * i * i;
    for (int j = i - 2; j >= 1; j -= 2) {
      ll diff = 1LL * j * j;
      if (sq - diff > n)
        break;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}