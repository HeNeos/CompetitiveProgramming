#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using Factor = pair<ll, int>;
using Factors = vector<pair<ll, int>>;

#define MAXN 17526000000000
#define N 15000000
vector<ll> triangular_numbers;

ll isqrt(ll n) {
  if (n <= 1)
    return n;
  ll z = n >> 2;
  ll r2 = 2 * isqrt(z);
  ll r3 = r2 + 1;
  return (n < r3 * r3) ? r2 : r3;
}

vi primes;
bitset<N> is_prime;

void sieve() {
  for (int i = 2; i < N; ++i) {
    if (!is_prime[i]) {
      primes.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i)
        is_prime[j] = 1;
    }
  }
}

vector<pll> solve(ll n, int last_p) {
  // y = (-1 +- sqrt(1-4x^2-4x+4n))/2
  // -4x^2-4x+1+4n = 0
  // -(2x+1)^2+2+4n = 0 -> (2x+1)^2 = 4n+2 -> x = (sqrt(4n+2)-1)/2,
  // (-sqrt(4n+2)-1)/2
  double low_sqrt = (-sqrtf64(static_cast<double>(n * 8 + 2)) - 1) / 2;
  double high_sqrt = (sqrtf64(static_cast<double>(n * 8 + 2)) - 1) / 2;
  vector<pll> solutions;
  for (ll root_1 = max(0LL, static_cast<ll>(ceil(low_sqrt)));
       root_1 <= min(static_cast<int>(high_sqrt), last_p); root_1++) {
    ll y = 1 - root_1 * root_1 * 4 - root_1 * 4 + n * 4;
    if (y < 0)
      break;
    ll root_2 = isqrt(y);
    if (1LL * root_2 * root_2 != y)
      continue;
    if (root_2 == 0) {
      if (-1 % 2 == 0) {
        solutions.push_back({root_1, -1 / 2});
      }
    } else {
      if (-1 - root_2 >= 0 && (-1 - root_2) % 2 == 0) {
        ll ans = (-1 - root_2) / 2;
        if (root_1 > ans)
          break;
        solutions.push_back({root_1, ans});
      }
      if (-1 + root_2 >= 0 && (-1 + root_2) % 2 == 0) {
        ll ans = (-1 + root_2) / 2;
        if (root_1 > ans)
          break;
        solutions.push_back({root_1, ans});
      }
    }
  }
  return solutions;
}

ll d(vll &divisors, ll r, ll m) {
  ll ans = 0;
  for (auto divisor : divisors) {
    if (divisor % m == r)
      ans++;
  }
  return ans;
}

ll e(vll &divisors, ll r, ll s, ll m) {
  return d(divisors, r, m) - d(divisors, s, m);
}

int kronecker(ll n) {
  ll sq = isqrt(n);
  return sq * sq == n;
}

Factors get_factorization(ll n) {
  Factors factors;
  for (auto prime : primes) {
    if (1LL * prime * prime > n)
      break;
    if (n % prime == 0) {
      int c = 0;
      while (n % prime == 0) {
        n /= prime;
        c++;
      }
      factors.push_back({prime, c});
    }
  }
  if (n != 1)
    factors.push_back({n, 1});
  return factors;
}

vll get_divisors(ll n) {
  vll divisors;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != n / i)
        divisors.push_back(n / i);
    }
  }
  return divisors;
}

void generate_divisors(ll n, Factors &factorization, vll &divisors,
                       int index = 0, ll d = 1) {
  if (d > n / d)
    return;
  if (index == factorization.size()) {
    divisors.push_back(d);
    if (d * d != n)
      divisors.push_back(n / d);
    return;
  }
  for (int i = 0; i <= factorization[index].second; ++i) {
    generate_divisors(n, factorization, divisors, index + 1, d);
    d *= factorization[index].first;
  }
}

ll solve(ll n) {
  // n = x^2+x+y^2+y+z^2+z
  // n = (x+1/2)^2 + ... - 3/4
  // 4n = (2x+1)^2 + ... - 3
  // 4n+3 = (2x+1)^2 + (2y+1)^2 + (2z+1)^2
  n = n * 8 + 3;
  vll divisors = get_divisors(n);
  ll ans = 4LL * e(divisors, 1, 3, 4) + 3LL * e(divisors, 1, 7, 8) +
           3LL * e(divisors, 3, 5, 8) + 5 * kronecker(n);

  if (n % 2 == 0)
    ans += 3 * kronecker(n / 2);
  if (n % 3 == 0)
    ans += 4 * kronecker(n / 3);

  for (int k = 1; 1LL * k * k < n; k += 2) {
    ll m = n - 1LL * k * k;
    while (!(m & 1))
      m >>= 1;
    Factors factorization = get_factorization(m);

    vll divs;
    generate_divisors(m, factorization, divs);
    ans += 2LL * e(divs, 1, 3, 4);
  }
  return ans / 12;
}

ll solve_2(ll n) {
  ll ans = 0;
  for (int i = 0; i < triangular_numbers.size(); i++) {
    ll x = triangular_numbers[i] * 2;
    if (n - x < 0)
      break;
    int lo = 0;
    int hi = triangular_numbers.size() - 1;
    while (lo < hi) {
      int me = lo + (hi - lo + 1) / 2;
      if (triangular_numbers[me] <= n - x)
        lo = me;
      else
        hi = me - 1;
    }
    ans += (triangular_numbers[lo] == n - x && lo != i);
  }
  return ans;
}

int solve_3(ll n) {
  if (n % 3 != 0)
    return 0;
  n /= 3;
  int lo = 0;
  int hi = triangular_numbers.size() - 1;
  while (lo < hi) {
    int me = lo + (hi - lo + 1) / 2;
    if (triangular_numbers[me] <= n)
      lo = me;
    else
      hi = me - 1;
  }
  return triangular_numbers[lo] == n;
}

void fill() {
  for (int i = 0;; i++) {
    ll x = 1LL * i * (i + 1) / 2;
    if (x > MAXN)
      break;
    triangular_numbers.push_back(x);
  }
}

int main() {
  fill();
  sieve();
  ll different_solutions = solve(MAXN) * 6;
  ll two_equal = solve_2(MAXN) * 3;
  ll three_equal = solve_3(MAXN) * 5;
  ll ans = different_solutions - two_equal - three_equal;
  cout << ans << '\n';
  return 0;
}