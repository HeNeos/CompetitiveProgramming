#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 90000000
bitset <N> primes;
vector <int> pr;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            pr.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << pr[n-1] << '\n';
    }
    return 0;
}