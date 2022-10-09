#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 3500005

int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

ll phi(ll x){
    ll ans = x;
    for(int i=2; 1LL*i*i<=x; i++){
        if(x%i == 0){
            while(x%i == 0) x /= i;
            ans -= ans/i;
        }
    }
    if(x > 1) ans -= ans/x;
    return ans;
}

void generate_divisors(ll n, int index, ll d, vector<pair <ll,int> > factorization, vector <ll> &ans){ 

    if(index == factorization.size()){
        ans.push_back(d);
        return;
    }
    for(int i = 0; i <= factorization[index].second; ++i){
        generate_divisors(n, index+1, d, factorization, ans); 
        d *= factorization[index].first;
    }
}


ll fastexp(ll nx, ll y, ll p){
    __int128 x = nx;
    x %= p;
    __int128 ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y >>= 1;
        x = (x*x)%p;
    }
    return (ll)(ans);
}

bool check_composite(ll n, ll a, ll d, int s){
    ll x = fastexp(a,d,n);
    if(x == 1 || x == n-1) return false;
    for(int r=1; r<s; r++){
        x = (1LL*x*x)%n;
        if(x == n-1) return false;
    }
    return true;
}

bool isPrime(ll p){
    if(p > 2000000){
        srand(time(NULL));
        for(int i=2; i<=10; i++){
            ll a = (1LL*rand())%p;
            ll verif = 1LL*fastexp(a,p,p);
            if(verif != a) return false;
        }
        return true;
    }
    else{
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
}

ll pollard(ll n){
    if(n == 1) return n;
    if(!(n&1)) return 2;
    ll x = (1LL*rand()%(n-2))+2;
    ll y = x;
    ll c = (1LL*rand()%(n-1)) + 1;
    ll d = 1LL;    
    while(d == 1){
        x = (1LL*fastexp(x,2,n)+c+n)%n;
        y = (1LL*fastexp(y,2,n)+c+n)%n;
        y = (1LL*fastexp(y,2,n)+c+n)%n;
        d = 1LL*__gcd(abs(x-y),n);
        if(d == n) return pollard(n);
    }
    return d;
}

void fact(ll n, map <ll, int> &f){
    if(n==1) return;
    if(isPrime(n)){
        f[n]++;
        return;
    }
    ll q = pollard(n);
    fact(q, f);
    fact(n/q, f);
}

int main(){
    FIFO;
    srand(time(NULL));
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll v;
        if(isPrime(n)) v = n-1;
        else v = phi(n);
        vector <ll> d;
        if(isPrime(v)){
            d.push_back(1);
            d.push_back(v);
        }
        else{
            map <ll, int> factor;
            fact(v, factor);
            generate_divisors(v, 0, 1, vector<pair<ll,int> >(factor.begin(),factor.end()), d);
        }
        ll minP = v;
        for(int j=0; j<d.size(); j++){
            ll res = fastexp(10, d[j], n);
            if(res == 1){
                minP = d[j];
                break;
            }
        }
        ll S = fastexp(10, minP, 9LL*n);
        S /= 9; S %= n;
        if(S == 0) cout << minP << '\n';
        else{
            ll g = __gcd(S, n);
            cout << 1LL*(n/g)*minP << '\n';
        }
    }
    return 0;
}
