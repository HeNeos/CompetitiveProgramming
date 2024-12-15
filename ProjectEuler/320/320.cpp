#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
using factors = map<int, ll>;

#define N 1000005
#define MULTIPLIER 1234567890
#define MOD 1000000000000000000

int lpf[N];
vector<int> primes;
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!lpf[i]) {
      lpf[i] = i;
      primes.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}

factors factorize(int n) {
  factors factorization;
  while (n > 1) {
    int f = lpf[n];
    int c = 0;
    while (n % f == 0) {
      n /= f;
      c++;
    }
    factorization[f] = c;
  }
  return factorization;
}

unordered_map<int, unordered_map<ll, ll>> cache_floor_series;
ll sum_floor_series(ll n, int k) {
  if (cache_floor_series.find(k) != cache_floor_series.end() &&
      cache_floor_series[k].find(n) != cache_floor_series[k].end())
    return cache_floor_series[k][n];
  ll ans = 0;
  while (n) {
    n /= k;
    ans += n;
  }
  cache_floor_series[k][n] = ans;
  return ans;
}

void merge(factors &a, factors &b) {
  for (auto factor : b) {
    a[factor.first] += 1LL * MULTIPLIER * factor.second;
  }
}

ll inv_legendre(ll lower_bound, ll higher_bound, int prime, ll exp) {
  while (lower_bound < higher_bound) {
    ll mid = lower_bound + (higher_bound - lower_bound) / 2;
    ll sum = sum_floor_series(mid, prime);
    if (sum >= exp)
      higher_bound = mid;
    else
      lower_bound = mid + 1;
  }
  return lower_bound;
}

ll solve(int n, factors &previous_factorization, ll previous_ans) {
  factors current_factorization = factorize(n);
  merge(previous_factorization, current_factorization);
  ll lower_bound = 0;
  vector<int> test_primes;
  for (auto factor : current_factorization) {
    int prime = factor.first;
    ll exp = previous_factorization[prime];
    lower_bound = max(lower_bound, 1LL * exp * (prime - 1));
    test_primes.push_back(prime);
  }
  ll higher_bound = lower_bound + max(1 << 16, 2 * n);
  lower_bound = max(lower_bound, previous_ans);
  for (auto prime : test_primes) {
    ll t = inv_legendre(lower_bound, higher_bound, prime,
                        previous_factorization[prime]);
    previous_ans = max(previous_ans, t);
    lower_bound = previous_ans;
  };
  return previous_ans;
}

factors factorization;

void init() {
  int factorial_9 = 1;
  for (int i = 1; i < 10; i++)
    factorial_9 *= i;
  factorization = factorize(factorial_9);
  for (auto factor : factorization) {
    factorization[factor.first] = 1LL * MULTIPLIER * factor.second;
  }
}

int main() {
  sieve();
  init();
  int n;
  cin >> n;
  if (n == -1)
    n = 1000000;
  i128 ans = 0;
  ll current = 0;
  for (int i = 10; i <= n; i++) {
    current = solve(i, factorization, current);
    ans += current;
    ans %= MOD;
  }
  cout << (ll)(ans) << '\n';

  return 0;
}