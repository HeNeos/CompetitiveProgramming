#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define N 351520
#define N 20000000
#define TWO_SOLUTIONS 351520
#define MAXN 123567101113
#define BATCH 1000000000
ll START = 1;
ll END = BATCH;

ll Pochhammer(ll x, ll m, ll p) {
  ll result = 1;
  for (int i = 0; i < m; ++i) {
    result = (result * (x + i)) % p;
  }
  return result;
}

vector<ll> NTT(ll n, ll p) {
  vector<ll> result;
  if (floor(sqrt(n - 1)) == sqrt(n - 1)) {
    ll m = sqrt(n - 1);
    for (ll i = 0; i <= m * (m - 1); i += m) {
      result.push_back(Pochhammer(1 + i, m, p));
    }
    result.push_back(n);
  } else {
    ll m = floor(sqrt(n));
    for (ll i = 0; i <= m * (m - 1); i += m) {
      result.push_back(Pochhammer(1 + i, m, p));
    }
    for (ll i = 1 + pow(floor(sqrt(n)), 2); i <= n; ++i) {
      result.push_back(i);
    }
  }
  return result;
}

ll FactorialMod(ll n, ll p) {
  if (n >= p) {
    return 0;
  }

  vector<ll> ntt = NTT(n, p);
  ll result = 1;
  for (ll x : ntt) {
    result = (result * x) % p;
  }
  return result;
}

vector<int> prime;
vector<bool> is_prime(N, true);

void sieve() {
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

ll find_x(__int128 r, int p) {
  __int128 mod = 1LL * p * p;
  __int128 ans = (p + 1) / 2;
  __int128 r2 = r * r;
  ans *= ((1 + r2) % mod);
  ans %= mod;
  ans += 1;
  ans *= (r % mod);
  ans %= mod;
  return ans;
}

ll solve(vector<pair<ll, pair<ll, ll>>> &solutions, set<ll> &addit) {
  unsigned long long out = MAXN;
  pair<ll, pair<ll, ll>> lower_solution = solutions[0];
  ll repeated = 0;
  vector<ll> additional;
  additional.assign(addit.begin(), addit.end());
  int last_position = 0;
  while (true) {
    if (START > MAXN)
      break;
    if (END > MAXN)
      END = MAXN;
    unordered_set<ll> unique_solutions;
    for (auto sol : solutions) {
      if (sol.first < 100)
        continue;
      for (ll multiplier = START / sol.first; multiplier <= END / sol.first;
           multiplier++) {
        ll value = sol.first * multiplier;
        if (sol.second.first == -1)
          continue;
        if (value + sol.second.first <= END and
            value + sol.second.first >= START) {
          unique_solutions.insert(value + sol.second.first);
        }
        if (sol.second.second == -1)
          continue;
        if (value + sol.second.second <= END and
            value + sol.second.second >= START) {
          unique_solutions.insert(value + sol.second.second);
        }
      }
    }
    for (int i = last_position; i < additional.size(); i++) {
      if (additional[i] > END) {
        last_position = i;
        break;
      }
      if (additional[i] >= START)
        unique_solutions.insert(additional[i]);
    }
    for (auto sol : unique_solutions) {
      int res = sol % lower_solution.first;
      if (res == lower_solution.second.first or
          res == lower_solution.second.second)
        repeated++;
    }

    ll ans = unique_solutions.size();
    cout << "[" << START << " - " << END << "]: " << ans << '\n';
    START = END + 1;
    END += BATCH;
    if (END > MAXN)
      END = MAXN;
    out -= ans;
  }
  ll sol_25 = (MAXN - lower_solution.second.first) / lower_solution.first + 1 +
              (MAXN - lower_solution.second.second) / lower_solution.first + 1 -
              repeated;
  cout << "SOL FOR 25 " << sol_25 << '\n';
  cout << out << '\n';
  return out - sol_25;
}

int main() {
  sieve();
  vector<pair<ll, pair<ll, ll>>> solutions;
  set<ll> additional;
  for(int i=0; i<prime.size(); i++){
    int p = prime[i];
    if(i%100000 == 0){
      cout << p << '\n';
    }
    if (p % 4 != 1)
      continue;
    ll r_1 = FactorialMod((p - 1) / 2, p);
    r_1 = min(r_1, p - r_1);
    ll x_1 = find_x(r_1, p);
    ll r_2 = p - r_1;
    ll x_2 = find_x(r_2, p);
    ll p_2 = 1LL * p * p;
    if (x_1 > x_2)
      swap(x_1, x_2);
    pair<ll, ll> x = {x_1, x_2};
    if (p_2 > MAXN) {
      if (x_1 > MAXN)
        x.first = -1;
      if (x_2 > MAXN)
        x.second = -1;
    }
    if (x.first == -1 and x.second == -1)
      continue;
    if (p <= TWO_SOLUTIONS)
      solutions.push_back(make_pair(p_2, x));
    else {
      additional.insert(x.first);
      if (x.second != -1)
        additional.insert(x.second);
    }
  }
  cout << "FINISHED primes\n";
  prime.clear();
  is_prime.clear();
  // for (auto solution : solutions) {
  //   cout << solution.first << ": {" << solution.second.first << ", "
  //        << solution.second.second << "}\n";
  // }

  ll ans = solve(solutions, additional);
  cout << ans << '\n';
  return 0;
}
