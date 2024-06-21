#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

ll fastexp(ll x, ll y, ll p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (1LL * ans * x) % p;
    y = y >> 1;
    x = (1LL * x * x) % p;
  }
  return ans % p;
}

map<ll, ll> m;
int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> powers(n);
  ll powers_sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    powers_sum += a;
    powers[i] = a;
    m[-a]++;
  }
  for (auto v : m) {
    if (v.first < 0 and v.second >= x) {
      int next_power = v.second / x;
      int residue = v.second % x;
      m[v.first] = residue;
      m[v.first + 1] += next_power;
    }
  }
  powers.clear();
  vector<pair<int, int>> count_powers;
  for (auto i : m) {
    if (i.second > 0)
      count_powers.push_back(make_pair(-i.first, i.second));
  }
  ll old_sum = powers_sum;
  powers_sum = 0;
  for (auto power : count_powers)
    powers_sum += power.first;
  ll times = count_powers[0].second;
  ll power = count_powers[0].first;
  ll ans = fastexp(x, powers_sum - power, MOD) % MOD;
  ans *= fastexp(x, old_sum - powers_sum, MOD);
  cout << ans % MOD;
  return 0;
}
