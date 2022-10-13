#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define MAXN 500000
#define N 500005
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

int cont[N];
void fill(){
    for(int i=1; ; i++){
        ll sq = 2LL*i*i;
        if(sq > MAXN) break;
        for(int j=0; j<pr.size(); j++){
            ll v = sq + pr[j];
            if(v > MAXN) break;
            cont[v]++;
        }
    }
}

int main() {
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << cont[n] << '\n';
    }
    return 0;
}
