#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100000005
#define MAXN (10000000000000000 - 1)

bitset <N> primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
    primes[1] = 1;
}

int mobius[N];
int t[N];
int tt[N];
void cmob(){
    for(int i=1; i<N; i++){
        mobius[i] = 1;
        t[i] = 0;
        tt[i] = 0;
    }
    for(int i=1; i<N; i+=2){
        if(!primes[i]){
            if(i%4 == 3){
                for(ll j=i; j<N; j+=i){
                    t[j]++;
                    if(t[j] >= 2) mobius[j] *= -1;
                }
                for(ll j=1LL*i*i; j<N; j+=1LL*i*i){
                    mobius[j] *= -1;
                    tt[j]++;
                    if(tt[j] >= 2) mobius[j] = 0;
                }
                if(1LL*i*i > N/i) continue;
                for(ll j=1LL*i*i*i; j<N; j+=1LL*i*i*i) mobius[j] = 0;
            }
            else{
                for(ll j=i; j<N; j+=i) mobius[j] *= -1;
                for(ll j=1LL*i*i; j<N; j+=1LL*i*i) mobius[j] = 0;
            }
        }
    }
    for(int i=1; i<N; i+=2){
        if(t[i] > 2 && tt[i] == 0) mobius[i] *= (t[i] - 1);
    }
}


int main(){
    sieve();
    cmob();
    ll ans = 0;
    for(int i=1; i<=N; i+=2){
        if(1LL*i*i > MAXN) break;
        if(i%4 == 3 && t[i] < 2) continue;
        ans += 1LL*mobius[i]*((MAXN/(1LL*i*i) + 3)/4);
    }
    cout << ans << '\n';
    return 0;
}