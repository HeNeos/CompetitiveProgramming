#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][200][2];

ll digit_dp(int pos, ll sum, bool tight, const vector<int> &digits,
            int target_sum) {
  if (pos == digits.size()) {
    return (sum == target_sum) ? 1 : 0;
  }

  if (dp[pos][sum][tight] != -1) {
    return dp[pos][sum][tight];
  }

  int limit = tight ? digits[pos] : 9;
  ll answer = 0;

  for (int digit = 0; digit <= limit; ++digit) {
    answer += digit_dp(pos + 1, sum + digit, tight && (digit == limit), digits,
                       target_sum);
  }

  dp[pos][sum][tight] = answer;
  return answer;
}

ll find_numbers_with_digit_sum_target(ll n, ll target_sum) {
  vector<int> digits;
  while (n > 0) {
    digits.push_back(n % 10);
    n /= 10;
  }
  reverse(digits.begin(), digits.end());
  memset(dp, -1, sizeof(dp));
  return digit_dp(0, 0, 1, digits, target_sum);
}

vector<int> generate_primes(int limit) {
  vector<bool> is_prime(limit + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= sqrt(limit); ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= limit; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  ll n = 45009328011709400LL;
  int max_digit_sum = 180;
  vector<int> primes = generate_primes(max_digit_sum);
  ll ans = 0;
  for (int i = 0; i < primes.size(); ++i) {
    ll count = find_numbers_with_digit_sum_target(n, primes[i]);
    ans += count;
  }
  cout << ans << '\n';
  return 0;
}
