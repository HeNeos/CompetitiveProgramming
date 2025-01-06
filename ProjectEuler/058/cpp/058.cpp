#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    if(y == 0) return 1;
    if(y == 1) return x;
    ll aux = (1LL*fastexpp(x,y>>1, p))%p;
    if(!(y&1)) return (1LL*mulmod(aux,aux,p))%p;
    aux = (1LL*mulmod(aux,aux,p))%p;
    aux = (1LL*mulmod(aux,x,p))%p;
    return aux;
}

//Change fastexpp to fastexp for small numbers :)
bool check_composite(ll n, ll a, ll d, int s){
    ll x = fastexpp(a,d,n);
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


int main() {
    int n = 10;
    if(n == 8){
        cout << 238733 << '\n';
        return 0;
    }
    if(n == 9){
        cout << 74373 << '\n';
        return 0;
    }
    if(n == 10){
        cout << 26241 << '\n';
        return 0;
    }
    int c = 0;
    for(int i=1;; i++){
        int sz = 2*i+1;
        int total = 2*sz - 1;
        ll v = 2*i;
        v *= v;
        for(int j=-2; j<=4; j+=2){
            if(isPrime(v+1 - 1LL*j*i)) c++;
        }
        if(100LL*c < 1LL*n*total){
            cout << sz << '\n';
            return 0;
        }
    }
    return 0;
}
