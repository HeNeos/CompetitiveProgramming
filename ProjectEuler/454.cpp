#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 1000000000000LL
ll n, n_cbrt, n_sqrt;

struct Farey {
  int a = 0;
  int b = 1;
  int c = 1;
  int d = -1;
};

Farey farey;

ll find_root(ll x, int p) {
  ll lo = 1;
  ll hi = 3 * powf(x, 1. / p);
  while (lo < hi) {
    ll me = lo + (hi - lo + 1) / 2;
    ll root = 1;
    for (int i = 1; i <= p; i++)
      root *= me;
    if (root <= x)
      lo = me;
    else
      hi = me - 1;
  }
  return lo;
}

ll dirichlet_hyperbola(ll x) {
  ll ans = 0;
  ll x_sqrt = find_root(x, 2);
  for (int i = 1; i <= x_sqrt; i++)
    ans += x / i;
  ans *= 2;
  ans -= (x_sqrt) * (x_sqrt);
  return ans;
}

bool farey_sequence(ll x, Farey &f) {
  if (f.d == -1)
    f.d = x;
  do {
    int k = (x + f.b) / f.d;
    int next_c = k * f.c - f.a;
    int next_d = k * f.d - f.b;
    f.a = f.c;
    f.b = f.d;
    f.c = next_c;
    f.d = next_d;
    if (f.c > x)
      break;
  } while (f.a == 0);
  return f.c <= x;
}

ll solve() {
  ll ans = 0;
  for (int i = 1; i < n_cbrt; i++) {
    ll m = n / i;
    for (int x = 1; x <= i; x++)
      ans -= m / x;
    ans += dirichlet_hyperbola(m);
  }
  for (int i = n_cbrt; i <= n_sqrt; i++) {
    ll m = n / i;
    ll pivot = m / i;
    ans -= 1LL * pivot * i;
    for (ll y = 1; y <= pivot; y++)
      ans += m / y;
  }
  return ans;
}

ll solve2() {
  ll ans = 0;
  for (int i = 1; 1LL * i * i <= n; i++) {
    for (int j = i + 1; 1LL * j * i <= n; j++) {
      ans += n / (1LL * i * j);
    }
  }
  return ans;
}

ll solve3() {
  ll ans = 0;
  while (farey_sequence(n_sqrt, farey)) {
    int x = farey.a;
    int y = farey.b;
    ll p = 1LL * y * (x + y);
    if (p > n)
      continue;
    ans += n / p;
  }
  return ans;
}

// 1/x + 1/y = 1/n
// n<x<y<=MAXN
// x = x'(x'+y')k
// y = y'(x'+y')k
// g = (x'+y')k
// n = x'y'k
// gcd(x', y') = 1

int main() {
  cin >> n;
  if (n == -1)
    n = MAXN;
  n = min(n, MAXN);
  n_sqrt = find_root(n, 2);
  cout << solve3() << '\n';
  return 0;
}