#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000005

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

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

int main(){
    sieve();
    ll ans = 0;
    int count = 0;
    for(auto v: p){
        if(fastexp(10, 1000000000, 9*v) == 1){
            ans += v;
            count++;
        }
        if(count == 40) break;
    }
    cout << ans << '\n';
    return 0;
}