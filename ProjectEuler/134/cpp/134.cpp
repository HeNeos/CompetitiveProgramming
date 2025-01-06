#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000205

bitset <N> primes;
vector <pair<int, int> > p;

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y >>= 1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll inv(ll x, ll p){
    return fastexp(x, p-2, p);
}

void sieve(){
    int prev = 10;
    for(int i=2; i<N; i++){
        if(!primes[i]){
            if(i > prev) prev *= 10;
            p.push_back({i, prev});
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}


int main(){
    sieve();
    ll ans = 0;
    for(int i=2; i<p.size()-1; i++){
        if(p[i].first > 1000000) break;
        int p1 = p[i].first;
        int p2 = p[i+1].first;
        int n = (1LL*inv(p[i].second, p2)*(p2 - p1)) % p2;
        if(n <= 0) n += p2;
        ans += 1LL*n*p[i].second + p[i].first;
    }
    cout << ans << '\n';
    return 0;
}