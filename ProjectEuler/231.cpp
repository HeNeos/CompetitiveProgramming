#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair <int, int> pii;
typedef vector <pii> vii;
#define N 20000005

int lpf[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

void getFactorization(int n, vii &f){
    while(n > 1){
        int d = lpf[n];
        int c = 0;
        while(n%d == 0){
            n /= d;
            c++;
        }
        f.push_back(make_pair(d, c)); 
    }
}

ll gen(ll a, ll b){
    ll ans = 0;
    for(int i=a; i<=b; i++){
        vii aux;
        getFactorization(i, aux);
        for(auto v: aux){
            ans += (1LL*v.first*v.second);
        }
    }
    return ans;
}

int main() {
    sieve();
    ll num = gen(15000000+1, 20000000);
    ll den = gen(1, 20000000-15000000);
    

    cout << num-den << '\n';
    return 0;
}
