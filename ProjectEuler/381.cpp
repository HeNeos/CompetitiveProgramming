#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
using ll = long long;
#define N 100000005
// (p-1)! = -1 mod p
// (p-2)! = 1 mod p 
// (p-3)! = inv(p-2) mod p
// (p-4)! = inv(p-2)inv(p-3)
// (p-5)! = inv(p-2)inv(p-3)inv(p-4)

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll inv(ll x, ll p){
    return fastexp(x, p-2, p);
}

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
    ll ans = 0;
    for(int i=2; i<pr.size(); i++){
        int p = pr[i];
        ll s2 = inv(p-2, p);
        ll s3 = inv(p-3, p);
        ll s4 = inv(p-4, p);
        ll S = s2%p;
        S += (s2*s3)%p;
        S += ((s2*s3)%p * s4)%p;
        S %= p;
        ans += S;
    }
    cout << ans << '\n';
    return 0;
}