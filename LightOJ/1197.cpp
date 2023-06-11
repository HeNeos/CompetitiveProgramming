#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100005
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

vector <int> primes;
bitset <N> isPrime;
void sieve(){
    isPrime[0] = 1;
    isPrime[1] = 1;
    for(int i=2; i<N; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) isPrime[j] = 1;
        }
    }
}

int main(){
    FIFO;
    sieve();
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        ll a, b; cin >> a >> b;
        bitset <N> count;
        // 0 -> a
        // b-a -> b
        a = max(a, 2LL);
        for(int i=0; 1LL*primes[i]*primes[i] <= b; i++){
            ll next_multiple = (a + primes[i] - 1)/primes[i];
            next_multiple *= primes[i];
            if(next_multiple == primes[i]) next_multiple += primes[i];
            for(ll j=next_multiple; j<=b; j+=primes[i]){
                count[j-a] = 1;
            }
        }
        int ans = 0;
        for(int i=0; i<=(b-a); i++){
            if(count[i] == 0) ans++;
        }
        cout << "Case " << _ << ": " << ans << '\n'; 
    }
    return 0;
}