#include <bits/stdc++.h>
using namespace std;
using ll=__int128;

#define N 1000005
#define MAX 100000000000
#define MOD 2017

bool pp[N];
vector <ll> primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(!pp[i]){
            primes.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i)
                pp[j] = true;
        }
    }
}

ll fastexp(int a, int b, int p){
    if(b==0) return 1;
    if(b==1) return a%p;
    ll ans = fastexp(a,b/2,p);
    ans = (ans*ans)%p;
    if(b%2 == 1) ans = (ans*a)%p;
    return ans;
}

ll mulmod(ll a, ll b, ll p){
    ll x = 0, y = a%p;
    while(b>0){
        if(b%2==1) x = (x+y)%p;
        y = (y*2)%p;
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

bool check(int p, int e){
    p %= MOD;
    ll v = p+1;
    v %= MOD;
    if(e==2)
        return v == 0;
    v *= p;
    v %= MOD;
    v++; v %= MOD;
    if(e == 3)
        return v==0;
    v *= p;
    v %= MOD;
    v++; v%= MOD;
    return v==0;
}

int pr[12]={2,3,5,7,11,13,17,19,23,29,31,37};

bool c(ll n, ll a, ll d, ll s){
    ll x = fastexpp(a,d,n);
    if(x==1 or x==n-1) return false;
    for(int r=1; r<s; r++){
        x = 1LL*x*x;
        x %= n;
        if(x==n-1) return false;
    }
    return true;
}

bool isPrime(ll p){
    if(p<=1) return false;
    int r=0;
    ll d=p-1;
    while(!(d&1)){
        d >>=1;
        r++;
    }
    for(int i=0; i<12; i++){
        int value = pr[i];
        if(p==value) return true;
        if(c(p,value,d,r)) return false;
    }
    return true;
}

int main(){
    sieve();
    unsigned long long ans = 0;
    vector <pair <ll, ll> > uwu;
    for(int i=0; i<primes.size(); i++){
        if(primes[i]*primes[i] > MAX) break;
        for(int j=2; j<=4; j++){
            if(check(primes[i], j)){
                ll value = 1;
                for(int k=0; k<j-1; k++) value *= primes[i];
                uwu.push_back(make_pair(value, primes[i]));
                break;
            }
        }
    }
    for(ll i=2;; i+=2){
        ll v = i*2017-1;
        if(v > MAX) break;
        if(v*v <= MAX) continue;
        if(isPrime(v)){
            uwu.push_back(make_pair(v, v));
        }
    }
    sort(uwu.begin(), uwu.end());
    vector <pair <ll, ll> > minor_values;
    vector <ll> big_values;
    for(auto v: uwu){
        // if(v.first*uwu[0].first <= MAX){
        //     minor_values.push_back(make_pair(v.first, v.second));
        // }
        // else{
            big_values.push_back(v.first);
        // }
    }
    // vector <ll> V;
    // for(auto v: minor_values){
    //     for(ll i=1;; i++){
    //         if(i%v.second == 0) continue;
    //         ll value = v.first*i;
    //         if(value > MAX) break;
    //         V.push_back(value);
    //     }
    // }
    // sort(V.begin(), V.end());
    // auto ip = unique(V.begin(), V.end());
    // V.resize(distance(V.begin(), ip));
    // for(auto v: V)
    //     ans += v;
    for(auto v: big_values){
        ll amount = MAX/v;
        ll value = amount;
        value *= (amount+1);
        value /= 2;
        value *= v;
        ans += value;
        ans -= value*value*(MAX/(value*value))*(MAX/(value*value) + 1)/2;
    }
    cout << ans - 1LL* 12101 * 2311 * 2311 << '\n';
    return 0;
}