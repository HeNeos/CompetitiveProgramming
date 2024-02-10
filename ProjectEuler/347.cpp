#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 10000000

bitset <N> primes;
vector <int> p;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            p.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

ll calc(int n, int p1, int p2){
    ll max_v = 1;
    n = n/(1LL*p1*p2);
    ll p_1 = 1;
    for(int a=0; p_1<=n; a++){
        ll p_2 = 1;
        for(int b=0;; b++){
            ll current = 1LL*p_1*p_2;
            if(current > n) break;
            max_v = max(max_v, current);
            p_2 *= p2;
        }
        p_1 *= p1;
    }
    return 1LL * max_v * p1 * p2;
}

ll solve(int n){
    ll ans = 0;
    for(int i=0; i<p.size(); i++){
        for(int j=i+1; j<p.size(); j++){
            int p1 = p[i];
            int p2 = p[j];
            if(1LL*p1*p2 > n) break;
            ans += calc(n, p1, p2);
        }
    }
    return ans;
}

int main(){
    sieve();
    cout << solve(N) << '\n';
    return 0;
}