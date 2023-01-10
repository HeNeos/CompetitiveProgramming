#include <iostream>
using namespace std;
using ll = long long;
#define HN 40000005
#define N 100000005
// #define MAXN 10000000000000000
#define MAXN (4096 - 1)

int hilbert[HN];
int lpf[N];

void sieve(){
    for(int i=0; i<HN; i++)
        hilbert[i] = 4*i+1;
    for(int i=1; i<HN; i++){
        if(hilbert[i] >= N) break;
        if(!lpf[hilbert[i]]){
            lpf[hilbert[i]] = hilbert[i];
            for(ll j=2LL*hilbert[i]; j<N; j+=hilbert[i]){
                if(lpf[j] == 0) lpf[j] = hilbert[i];
            }
        }
    }
}

int calc_mob(ll n){
    int ans = 1;
    while(n > 1){
        ll d = lpf[n];
        int c = 0;
        while(n%d == 0){
            n /= d;
            c++;
        }
        if(c >= 2) return 0;
        ans *= -1;
    }
    return ans;
}

int main(){
    sieve();
    //ll ans = (MAXN+3)/4;
    ll ans = 0;
    for(int i=0; i<HN; i++){
        ll h = 1LL*hilbert[i]*hilbert[i];
        if(h > MAXN) break;
        ll val = MAXN/h;
        val = (val-1)/4 + 1;
        // 1 ... 50
        // 1 5 9 ... 49 -> 13
        cout << i << " " << hilbert[i] << " " << calc_mob(hilbert[i]) << " " << val << endl;
        ans += 1LL*calc_mob(hilbert[i])*val;
    }
    cout << ans << '\n';
    return 0;
}



// n/h^2 -> h^2*1, h^2*2, h^2*3, ... 
// 25 125 225 ... 925
// 