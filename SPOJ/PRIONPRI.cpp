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




int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(isPrime(n)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}