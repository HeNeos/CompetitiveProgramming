#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector <ll> H[16];
vector <ll> strong_H;

int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll mulmod(ll a, ll b, ll p){
    ll x = 0, y = a%p;
    while(b>0){
        if(b%2==1) x = (x+y)%p;
        y = (1LL*y*2)%p;
        b = b/2;
    }
    return x%p;
}

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = mulmod(ans,x,p);
        y = y>>1;
        x = mulmod(x,x,p);
    }
    return ans%p;
}


//Change fastexpp to fastexp for small numbers :)
bool check_composite(ll n, ll a, ll d, int s){
    __int128 x = fastexpp(a,d,n);
    if(x == 1 || x == n-1) return false;
    for(int r=1; r<s; r++){
        x = (1LL*x*x)%n;
        if(x == n-1) return false;
    }
    return true;
}

bool isPrime(ll p){
    if(p<=1) return false;
    int r = 0;
    ll d = p-1;
    while(!(d&1)){
        d >>= 1;
        r++;
    }
    for(int i=0; i<12; i++){
        int value = TestMillerRabin[i];
        if(p == value) return true;
        if(check_composite(p,value,d,r)) return false;
    }
    return true;
}

void gen_H(int n){
    for(auto v: H[n-1]){
        for(int i=0; i<=9; i++){
            ll x = v;
            int s = 0;
            while(x > 0){
                s += x%10;
                x /= 10;
            }
            s += i;
            x = 10LL*v + i;
            if(x%s == 0){
                H[n].push_back(x);
                if(isPrime(x/s)) strong_H.push_back(x);
            }
        }
    }
}

int main(){
    unsigned long long ans = 0;
    for(int i=1; i<=9; i++) H[1].push_back(i);
    for(int i=2; i<14; i++) gen_H(i);
    for(auto x: strong_H){
        for(int i=0; i<=9; i++){
            if(isPrime(10LL*x + i)){
                ans += 10LL*x+i;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}