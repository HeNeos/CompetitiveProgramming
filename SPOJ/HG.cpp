#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1000005

#define MOD 1000000000

bitset<N> primes;
vector<int> p;
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!primes[i]) {
      p.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i)
        primes[j] = 1;
    }
  }
}

ll fastexp(ll x, ll y, ll p, bool &trim) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1) {
      ll a = (ans * x);
      if (a >= p) {
        a %= p;
        trim = true;
      }
      ans = a;
    }
    y = y >> 1;
    ll a = (x * x);
    if (a >= p) {
      a %= p;
      trim = true;
    }
    x = a;
  }
  if (ans >= p)
    trim = true;
  return ans % p;
}

vector<pair<int, int>> merge(vector<pair<int, int>> &a,
                             vector<pair<int, int>> &b) {
  int n = a.size();
  int m = b.size();
  int p1 = 0;
  int p2 = 0;
  vector<pair<int, int>> ans;
  for (;;) {
    if (p1 >= n and p2 >= m)
      break;
    if (p1 >= n) {
      ans.push_back(b[p2]);
      p2++;
      continue;
    }
    if (p2 >= m) {
      ans.push_back(a[p1]);
      p1++;
      continue;
    }
    int value = 0;
    int amount = 0;
    if (a[p1].first >= b[p2].first) {
      value = b[p2].first;
      amount += b[p2].second;
    }
    if (a[p1].first <= b[p2].first) {
      value = a[p1].first;
      amount += a[p1].second;
    }
    ans.push_back(make_pair(value, amount));
    if (a[p1].first > b[p2].first) {
      p2++;
      continue;
    }
    if (a[p1].first < b[p2].first) {
      p1++;
      continue;
    }
    if (a[p1].first == b[p2].first) {
      p1++;
      p2++;
      continue;
    }
  }
  return ans;
}

vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> f;
  for (int i = 0; i < p.size(); i++) {
    int prime = p[i];
    if (1LL * prime * prime > n)
      break;
    int c = 0;
    while (n % prime == 0) {
      n /= prime;
      c++;
    }
    if (c)
      f.push_back(make_pair(prime, c));
  }
  if (n != 1)
    f.push_back(make_pair(n, 1));
  return f;
}

vector<pair<int, int>> factorize(vector<int> n) {
  vector<vector<pair<int, int>>> f;
  for (int i = 0; i < n.size(); i++)
    f.push_back(factorize(n[i]));
  vector<pair<int, int>> current = f[0];
  for (int i = 1; i < f.size(); i++)
    current = merge(current, f[i]);
  return current;
}

void gcd(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
  bool trim = false;
  int n = a.size();
  int m = b.size();
  ll ans = 1;
  int p1 = 0;
  int p2 = 0;
  for (;;) {
    if (p1 >= n or p2 >= m)
      break;
    int value = 0;
    int amount = 0;
    if (a[p1].first == b[p2].first) {
      ans *= fastexp(b[p2].first, min(a[p1].second, b[p2].second), MOD, trim);
      if (ans >= MOD) {
        ans %= MOD;
        trim = true;
      }
      p1++;
      p2++;
      continue;
    }
    if (a[p1].first < b[p2].first) {
      p1++;
      continue;
    }
    if (a[p1].first > b[p2].first) {
      p2++;
      continue;
    }
  }
  string x = to_string(ans);
  if (x.size() <= 9 and !trim)
    cout << x;
  else {
    for (int i = 0; i < 9 - x.size(); i++)
      cout << '0';
    cout << x;
  }
  cout << endl;
}

int main() {
  sieve();
  int n;
  cin >> n;
  vector<int> v_n(n);
  for (int i = 0; i < n; i++)
    cin >> v_n[i];
  vector<pair<int, int>> f_n = factorize(v_n);
  int m;
  cin >> m;
  vector<int> v_m(m);
  for (int i = 0; i < m; i++)
    cin >> v_m[i];
  vector<pair<int, int>> f_m = factorize(v_m);
  gcd(f_n, f_m);
  return 0;
}
