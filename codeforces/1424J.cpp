#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000005
int primes[N];
void sieve(){
    for(int i=2; i<N; i++) primes[i] = 1;
    for(int i=2; i<N; i++){
        if(primes[i] == 1){
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 0;
        }
    }
    for(int i=1; i<N; i++)
        primes[i] += primes[i-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << primes[n] - primes[(int)(sqrt(n*1.0))] + 1 << '\n';
    }
    return 0;
}