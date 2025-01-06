#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vii = vector<pii>;

#define N 20000005
#define MAXN 20000000

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

// data[i].first = x[i]
// data[i].second = m[i]
pll crt(vll data) {
  int n = data.size();
  ll a1 = data[0].first;
  ll m1 = data[0].second;
  for (int i = 1; i < n; i++) {
    ll a2 = data[i].first;
    ll m2 = data[i].second;
    ll p, q;
    extended_gcd(m1, m2, p, q);
    ll mod = m1 * m2;
    ll x = (a1 * m2 * q + a2 * m1 * p) % mod;
    a1 = x;
    if (a1 < 0)
      a1 += mod;
    m1 = mod;
  }
  return make_pair(a1, m1);
}

vector<int> p;
int lpf[N];
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!lpf[i]) {
      lpf[i] = i;
      p.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}
bitset<N> prime_powers;
void fill() {
  for (int i = 1; i < p.size(); i++) {
    ll x = p[i];
    while (x * p[i] < N) {
      x *= p[i];
      prime_powers[x] = 1;
    }
  }
}

vector<int> factorization(int n) {
  vector<int> factors;
  while (n > 1) {
    int value = 1;
    int d = lpf[n];
    while (n % d == 0) {
      n /= d;
      value *= d;
    }
    factors.push_back(value);
  }
  return factors;
}

vector<int> solve_primes(int n) {
  vector<int> residues;
  if (__builtin_popcount(n) == 1) {
    if (n > 4)
      residues = {1, n / 2 - 1, n / 2 + 1, n - 1};
    else if (n == 4)
      residues = {1, 3};
    else
      residues = {1};
    return residues;
  }
  if (lpf[n] == n or prime_powers[n]) {
    residues = {1, n - 1};
    return residues;
  }
}

ll solve(int n) {
  if (__builtin_popcount(n) == 1) {
    if (n <= 4)
      return 1;
    return n / 2 + 1;
  }
  if (lpf[n] == n or prime_powers[n]) {
    return 1;
  }
  ll largest_residue = 1;
  vector<int> factors = factorization(n);
  vector<pair<int, vector<int>>> residues;
  for (int i = 0; i < factors.size(); i++) {
    pair<int, vector<int>> current_residue;
    current_residue.first = factors[i];
    current_residue.second = solve_primes(factors[i]);
    residues.push_back(current_residue);
  }
  bool has_two = __builtin_popcount(residues[0].first) == 1;
  int two_residues = has_two ? residues[0].second.size() : 0;
  int other_residues = factors.size() - has_two;
  for (int i = 0; i < (1 << other_residues); i++) {
    vll mod_equations(other_residues);
    for (int j = 0; j < other_residues; j++) {
      int mod = residues[has_two + j].first;
      int value = (i & (1 << j)) ? residues[has_two + j].second[1]
                                 : residues[has_two + j].second[0];
      mod_equations[j] = {value, mod};
    }
    if (has_two) {
      for (int j = 0; j < two_residues; j++) {
        int mod = residues[0].first;
        int value = residues[0].second[j];
        mod_equations.push_back({value, mod});
        pll mod_residue = crt(mod_equations);
        if (mod_residue.first != mod_residue.second - 1)
          largest_residue = max(largest_residue, mod_residue.first);
        mod_equations.pop_back();
      }
    } else {
      pll mod_residue = crt(mod_equations);
      if (mod_residue.first != mod_residue.second - 1)
        largest_residue = max(largest_residue, mod_residue.first);
    }
  }
  return largest_residue;
}

int main() {
  sieve();
  fill();
  int n;
  cin >> n;
  if (n == -1)
    n = MAXN;
  n = min(n, MAXN);
  ll ans = 0;
  for (int i = 3; i <= n; i++) {
    int out = solve(i);
    ans += out;
  }
  cout << ans << '\n';
  return 0;
}
