#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;

#define N 10000005
#define FIFO                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

int lpf[N];
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!lpf[i]) {
      lpf[i] = i;
      for (ll j = 1LL * i * i; j < N; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}

// factorization[i] = (p,a): p^a
// Complexity = O(0.5*n^1/3)?
//  generate_divisors(n, 0, 1, &factorization, &ans)

void generate_divisors(int n, int index, int d, vii &factorization, vi &ans) {
  if (1LL * d * d > n)
    return;

  if (index == factorization.size()) {
    ans.push_back(d);
    if (d * d != n)
      ans.push_back(n / d);
    return;
  }
  for (int i = 0; i <= factorization[index].second; ++i) {
    generate_divisors(n, index + 1, d, factorization, ans);
    d *= factorization[index].first;
  }
}

vii factorize(int n) {
  vii factors;
  while (n != 1) {
    int d = lpf[n];
    int c = 0;
    while (n % d == 0) {
      c++;
      n /= d;
    }
    factors.push_back({d, c});
  }
  return factors;
}

vi get_divisors(int n) {
  vii factorization = factorize(n);
  vi divisors;
  generate_divisors(n, 0, 1, factorization, divisors);
  return divisors;
}
unordered_map<int, int> cache_ans;
int main() {
  FIFO;
  sieve();
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pii> ans(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (cache_ans.find(a[i]) != cache_ans.end()) {
      ans[i].first = cache_ans[a[i]];
      ans[i].second = a[i] / ans[i].first;
      continue;
    }
    ans[i].first = -1;
    ans[i].second = -1;
    vi divisors = get_divisors(a[i]);
    for (auto divisor : divisors) {
      int complement_divisor = a[i] / divisor;
      if (divisor == 1 or divisor > complement_divisor)
        continue;
      if (__gcd(divisor + complement_divisor, a[i]) == 1) {
        ans[i].first = divisor;
        ans[i].second = complement_divisor;
        cache_ans[a[i]] = divisor;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << min(ans[i].first, ans[i].second) << " ";
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << max(ans[i].first, ans[i].second) << " ";
  }
  cout << '\n';
  return 0;
}