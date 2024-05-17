#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define N 35000005
#define MAXN 10000000000000000

int lpf[N];
vector<int> primes;

void sieve() {
  for (int i = 2; i < N; i++) {
    if (lpf[i] == 0) {
      lpf[i] = i;
      primes.push_back(i);
      for (ll j = 2LL * i; j < N; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}

ll divisors_sum[N];

void fill() {
  for (int i = 1; i < N; i++) {
    for (ll j = i; j < N; j += i)
      divisors_sum[j] += i;
  }
}

vector<pair<int, int>> factorization(ll n) {
  vector<pair<int, int>> factors;
  if (n < N) {
    while (n != 1) {
      int d = lpf[n];
      int c = 0;
      while (n % d == 0) {
        n /= d;
        c++;
      }
      factors.push_back({d, c});
    }
  } else {
    for (int i = 2; 1LL * i * i <= n; i++) {
      if (n % i == 0) {
        int c = 0;
        while (n % i == 0) {
          n /= i;
          c++;
        }
        factors.push_back({i, c});
      }
    }
    if (n != 1)
      factors.push_back({n, 1});
  }
  return factors;
}

vector<int> get_divisors(int n) {
  vector<int> ans;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i != n / i)
        ans.push_back(n / i);
    }
  }
  return ans;
}

unordered_map<string, ll> cache;

string get_key(vector<int> alphas) {
  string key = "";
  sort(alphas.begin(), alphas.end());
  for (auto exponent : alphas)
    key += to_string(exponent) + "#";
  return key;
}

string get_key(vector<pair<int, int>> &factors) {
  vector<int> exponents;
  for (auto x : factors) {
    exponents.push_back(x.second);
  }
  return get_key(exponents);
}

ll f(int n) {
  if (n == 1 or lpf[n] == n)
    return 1;
  vector<pair<int, int>> factors = factorization(n);
  if (factors.size() == 1)
    return (1LL << (factors[0].second - 1));
  string key = get_key(factors);
  if (cache.find(key) != cache.end())
    return cache[key];
  vector<int> d = get_divisors(n);
  ll ans = 0;
  for (auto x : d) {
    if (n != x)
      ans += f(x);
  }
  cache[key] = ans;
  return ans;
}

vector<int> trim(vector<int> v) {
  vector<int> ans;
  for (auto x : v) {
    if (x)
      ans.push_back(x);
  }
  return ans;
}

vector<int> get_previous(vector<int> &v, vector<int> &original) {
  vector<int> ans = v;
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i] == 0) {
      ans[i] = original[i];
      continue;
    } else {
      ans[i]--;
      break;
    }
  }
  return ans;
}

ll g(vector<int> &alphas) {
  sort(alphas.begin(), alphas.end());
  if (alphas.size() == 0)
    return 1;
  if (alphas.size() == 1)
    return (1LL << (alphas[0] - 1));
  if (alphas.size() == 2) {
    if (alphas[0] == 1) {
      return ((1LL << alphas[1]) + (1LL << (alphas[1] - 1)) * alphas[1]);
    } else {
      ll b = (1LL << alphas[1]);
      ll c = 3LL * (1LL << (alphas[1] - 1)) * (alphas[1] + 1);
      ll d = (1LL << (alphas[1] - 2)) * (alphas[1] * alphas[1] + alphas[1] - 2);
      return b + c + d;
    }
  }
  string key = get_key(alphas);
  if (cache.find(key) != cache.end())
    return cache[key];
  ll ans = 0;
  vector<int> current = alphas;
  while (
      !all_of(current.begin(), current.end(), [](int i) { return i == 0; })) {
    current = get_previous(current, alphas);
    vector<int> trimmed = trim(current);
    ans += g(trimmed);
  }
  cache[key] = ans;
  return ans;
}

int main() {
  sieve();
  for (int i = 4; i < 10000; i += 4)
    f(i);

  unsigned long long out = 1;
  for (int a = 0; 6 * a < 12; a++) {
    for (int b = a; a + 5 * b < 12; b++) {
      for (int c = b; a + b + 4 * c < 12; c++) {
        for (int d = c; a + b + c + 3 * d < 12; d++) {
          for (int e = d; a + b + c + d + 2 * e < 24; e++) {
            for (int f = e; a + b + c + d + e + f < 48; f++) {
              if (a + b + c + d + e + f == 0)
                continue;
              vector<int> vv = {a, b, c, d, e, f};
              vector<int> v;
              for (int i = 0; i < vv.size(); i++) {
                if (vv[i])
                  v.push_back(vv[i]);
              }
              ll ans = g(v);
              if (ans > MAXN or ans <= 0)
                break;
              vector<pair<int, int>> factors = factorization(ans);
              if (get_key(v) == get_key(factors)) {
                out += ans;
                cout << a << " " << b << " " << c << " " << d << " " << e << " "
                     << f << " " << ans << '\n';
              }
            }
          }
        }
      }
    }
  }
  cout << out << '\n';
  return 0;
}
