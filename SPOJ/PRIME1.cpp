#include <bits/stdc++.h>
using namespace std;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define N 40000
using ll = long long;

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

void solve(ll l, ll r){
    vector <bool> isPrime(r-l+1, true);
    for(ll i=0; i<p.size(); i++){
        for(ll j=max(1LL*p[i]*p[i], 1LL*(l+p[i]-1)/p[i]*p[i]); j<=r; j+=p[i]){
            isPrime[j-l] = false;
        }
    }
    if(l == 1) isPrime[0] = false;
    for(ll i=l; i<=r; i++){
        if(isPrime[i-l]) cout << i << '\n';
    }
}

int main(){
    FIFO;
    sieve();
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        solve(n, m);
        cout << '\n';
    }
    return 0;
}