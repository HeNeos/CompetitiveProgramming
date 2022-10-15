#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
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

vector <int> pandigital;
vector <int> prime_p;
void fill(){
    for(int digits=1; digits<=9; digits++){
        vector <int> tmp(digits);
        for(int i=0; i<digits; i++) tmp[i] = i+1;
        do{
            if(tmp.back()%2 == 0) continue;
            if(tmp.back() == 5) continue;
            ll value = 0;
            for(int i=0; i<digits; i++){
                value *= 10;
                value += tmp[i];
            }
            pandigital.push_back(value);
        }while(next_permutation(tmp.begin(), tmp.end()));
    }
    for(int i=0; i<pandigital.size(); i++){
        if(isPrime(pandigital[i])) prime_p.push_back(pandigital[i]);
    }
}

int main() {
    fill();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        int lo = 0; int hi = prime_p.size() - 1;
        while(lo < hi){
            int me = lo + (hi - lo + 1)/2;
            if(prime_p[me] <= n) lo = me;
            else hi = me-1;
        }
        if(prime_p[lo] > n) cout << -1 << '\n';
        else cout << prime_p[lo] << '\n';
    }
    return 0;
}
