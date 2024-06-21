#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll b;
  cin >> b;
  ll ans = 0;
  for (int i = 1; 1LL * i * i <= b; i++) {
    if (b % i == 0) {
      ans++;
      if (i != b / i)
        ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}