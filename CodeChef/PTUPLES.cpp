#include <iostream>
#include <bitset>
#include <vector>
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

int ans[N];

void fill(){
    for(int i=5; i<N; i++){
        if(!primes[i] && !primes[i-2])
            ans[i] = ans[i-1] + 1;
        else ans[i] = ans[i-1];
    }
}

int main(){
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}
