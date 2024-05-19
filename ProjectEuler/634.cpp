using namespace std;
using ll = long long;
using ull = unsigned long long;

#define N 1400000
const ull MAXN = 9000000000000000000;

int lpf[N];
vector<int> p;
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

int mobius[N];
void cmob() {
  mobius[1] = 1;
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i)
      mobius[i] = -1;
    else {
      if (lpf[i / lpf[i]] == lpf[i])
        mobius[i] = 0;
      else
        mobius[i] = -1 * mobius[i / lpf[i]];
    }
  }
}

int prime_sqrt[N];

ll remove_multiples(ll n, int max_prime) {
  ll ans = 0;
  vector<ll> base_numbers;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] >= max_prime)
      break;
    if (1LL * p[i] * p[i] * p[i] > n)
      break;
    base_numbers.push_back(1LL * p[i] * p[i] * p[i]);
  }

  int sz = base_numbers.size();
  for (int i = 1; i < (1 << sz); i++) {
    ll product = 1;
    int c = 0;
    for (int j = 0; j < sz; j++) {
      if ((1 << j) & i) {
        product *= base_numbers[j];
        c++;
      }
    }
    if (c % 2 == 0)
      ans -= n / product;
    else
      ans += n / product;
  }

  return ans;
}

void fill() {
  for (auto prime : p) {
    if (prime * prime >= N)
      break;
    prime_sqrt[prime * prime] = prime;
  }
}

int main() {
  sieve();
  cmob();
  fill();
  ull ans = 0;
  for (int i = 2;; i++) {
    if (!(mobius[i] != 0 or prime_sqrt[i]))
      continue;
    ull p1 = 1LL * i * i * i;
    if (4 > MAXN / p1)
      break;
    ll limit = sqrt(MAXN / p1);
    ans += limit - 1;
    if (prime_sqrt[i]) {
      int p_sqrt = prime_sqrt[i];
      ans -= remove_multiples(limit, p_sqrt);
    }
  }
  cout << ans << '\n';
  return 0;
}
