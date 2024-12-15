#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 10000000000000000
// #define MOD 100000000

ll fastexp(ll x, ll y, ll p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return ans % p;
}

int residues_frequency[250];
ll ans[250];

void fill(int n) {
  for (int i = 1; i <= n; i++) {
    residues_frequency[fastexp(i, i, 250)]++;
  }
}

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = 250250;
  n = min(n, 250250);
  fill(n);

  ans[0] = 1;
  for (int i = 0; i < 250; i++) {
    for (int j = 0; j < residues_frequency[i]; j++) {
      ll temp[250];
      for (int k = 0; k < 250; k++) {
        int pos = k - i;
        if (pos < 0)
          pos += 250;
        temp[k] = (ans[k] + ans[pos]) % MOD;
      }
      for (int k = 0; k < 250; k++)
        ans[k] = temp[k];
    }
  }
  cout << (ans[0] - 1) % MOD << '\n';
  return 0;
}