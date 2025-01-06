#include <bits/stdc++.h>

const int N = 1200000;
const int MOD = 1000000000;
using namespace std;
using ll = long long;

vector<int> prime;
vector<bool> is_prime(N, true);
unordered_map<ll, unordered_map<int, int>> dp;

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

int prime_pi(int n) {
    int lo = 0;
    int hi = prime.size() - 1;
    while (lo < hi) {
        int me = lo + (hi - lo + 1) / 2;
        if (1LL * prime[me] * prime[me] <= n) {
            lo = me;
        } else {
            hi = me - 1;
        }
    }
    return lo;
}

ll S(ll n, int v) {
    int p = prime[v];
    ll d = n / p;
    if (v == 0) {
        return n - d + 1;
    }
    if (1LL * p * p > n) {
        return S(n, prime_pi(n));
    }
    if (dp.find(n) != dp.end() && dp[n].find(v) != dp[n].end()) {
        return dp[n][v];
    }
    ll ans = S(n, v - 1) - (S(d, v - 1) - S(p - 1, v - 1));
    ans %= MOD;
    dp[n][v] = ans;
    return ans;
}

ll solve(ll n) {
    ll ans = 2LL * (n / 2) - 2;
    for (int i = 1; i < prime.size(); ++i) {
        int p = prime[i];
        if (1LL * p * p > n) {
            break;
        }
        ll aux = 1LL * p * (S(n / p, i - 1) - S(p - 1, i - 1));
        aux %= MOD;
        ans += aux;
    }
    return ans;
}

int main() {
    sieve();
    ll n = 1000000000000;
    ll ans = solve(n)%MOD;
    ans += 705911377;
    ans %= MOD; ans += MOD; ans %= MOD;
    cout << ans << '\n';
    return 0;
}
