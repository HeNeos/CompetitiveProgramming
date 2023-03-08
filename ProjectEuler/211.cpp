#include <bits/stdc++.h>
using namespace std;
using ll=__int128;

#define N 64000005
ll s_2[N];

void sieve(){
    for(ll i=1; i<N; i++){
        for(ll j=i; j<N; j+=i)
            s_2[j] += i*i;
    }
}

bool check(ll x){
    ll lo = 1;
    ll hi = 2LL*(long long)(sqrt(1.0*x));
    while(lo < hi){
        ll me = lo + (hi-lo+1)/2;
        if(me*me <= x) lo = me;
        else hi = me-1;
    }
    return lo*lo == x;
}

int main(){
    sieve();
    unsigned long long ans = 0;
    for(int i=1; i<N-5; i++){
        if(check(s_2[i])){
            ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}