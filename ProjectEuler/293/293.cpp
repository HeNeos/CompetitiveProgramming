#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000000000

int base_primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
vector<int> admissible_numbers;

int TestMillerRabin[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

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

// Change fastexpp to fastexp for small numbers :)
bool check_composite(ll n, ll a, ll d, int s) {
  ll x = fastexp(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (1LL * x * x) % n;
    if (x == n - 1)
      return false;
  }
  return true;
}

bool is_prime(ll p) {
  if (p <= 1)
    return false;
  int r = 0;
  ll d = p - 1;
  while (!(d & 1)) {
    d >>= 1;
    r++;
  }
  for (int i = 0; i < 12; i++) {
    int value = TestMillerRabin[i];
    if (p == value)
      return true;
    if (check_composite(p, value, d, r))
      return false;
  }
  return true;
}

void fill() {
  vector<int> numbers[9];
  for (int i = 1;; i++) {
    if ((1 << i) >= N)
      break;
    numbers[0].push_back((1 << i));
  }
  for (int primes_amount = 2; primes_amount <= 9; primes_amount++) {
    for (auto number : numbers[primes_amount - 2]) {
      for (ll prime_power = base_primes[primes_amount - 1];;
           prime_power *= base_primes[primes_amount - 1]) {
        ll new_number = prime_power * number;
        if (new_number >= N)
          break;
        numbers[primes_amount - 1].push_back(new_number);
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (auto number : numbers[i]) {
      admissible_numbers.push_back(number);
    }
  }
}

int main() {
  fill();
  set<int> pseudo_fortunate;
  int ans = 0;
  sort(admissible_numbers.begin(), admissible_numbers.end());
  for (auto admissible_number : admissible_numbers) {
    for (int j = 3; j < 1000; j += 2) {
      if (is_prime(admissible_number + j)) {
        if (pseudo_fortunate.find(j) == pseudo_fortunate.end()) {
          pseudo_fortunate.insert(j);
          ans += j;
        }
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}