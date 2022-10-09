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


int main() {
    sieve();
    int n; cin >> n;
    int a_ans = 0; int b_ans = 0;
    int c = -1;
    for(int a=-n; a<n; a++){
        for(int b=-n; b<n; b++){
            for(int n_ = 0;; n_++){
                int v = n_*n_ + a*n_ + b;
                if(v < 2) break;
                if(primes[v]) break;
                if(n_ > c){
                    a_ans = a;
                    b_ans = b;
                    c = n_;
                }
            }
        }
    }
    cout << a_ans << " " << b_ans << '\n';
    return 0;
}
