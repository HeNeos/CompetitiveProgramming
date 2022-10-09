#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define N 1000005

bitset <N> primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

ll dp[N];

void fill(){
    dp[2] = 2;
    for(int i=3; i<N; i++)
        dp[i] = dp[i-1] + i*(!primes[i]);
}

int main(){
    sieve();
    fill();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
