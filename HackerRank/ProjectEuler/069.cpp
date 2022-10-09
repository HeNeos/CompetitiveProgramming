#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
#define N 80
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


int main() {
    sieve();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll ans = 1;
        for(auto prime: p){
            if(ans*prime >= n) break;
            ans *= prime;
        }
        cout << ans << '\n';
    }
    return 0;
}
