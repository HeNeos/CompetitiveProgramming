#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vii = vector<pair<int, int>>;

#define INF (1LL << 62);

vii residues;
void read_preprocess() {
  int p;
  int sq;
  while (cin >> p >> sq)
    residues.push_back({p, sq});
}

ll fastexp(ll x, ll y, ll p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return ans % p;
}

ll inv(ll x, ll p) { return fastexp(x, p - 2, p); }

int solve(int n, int p) {
  ll m = (1LL * n * n - 3LL * n - 1) / p;
  ll k = inv(2LL * n - 3, p) * -m;
  k %= p;
  k += p;
  k %= p;
  return k;
}

int main() {
  ll ans = 0;
  read_preprocess();
  for (auto residue : residues) {
    int prime = residue.first;
    if (prime == 2)
      continue;
    int n_1 = (3 + residue.second) / 2;
    int n_2 = (3 - residue.second) / 2;
    n_1 %= prime;
    n_2 %= prime;
    n_1 += prime;
    n_2 += prime;
    n_1 %= prime;
    n_2 %= prime;
    ll k_1 = solve(n_1, prime);
    ll ans_1 = n_1 + k_1 * prime;
    ll ans_2 = INF;
    if (n_1 != n_2) {
      ll k_2 = solve(n_2, prime);
      ans_2 = n_2 + k_2 * prime;
    }
    ans += min(ans_1, ans_2);
  }
  cout << ans << '\n';
  return 0;
}