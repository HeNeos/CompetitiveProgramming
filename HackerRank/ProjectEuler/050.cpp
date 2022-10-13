#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define N 500005

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
    if(p < N) return !primes[p];
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

vector <ll> S;

void fill(){
    int sz = pr.size();
    S.resize(sz+1);
    S[0] = 0;
    for(int i=1; i<=sz; i++)
        S[i] = S[i-1] + pr[i-1];
}

void solve(ll n){
    int max_len = 0;
    ll ans = 0;
    int sz = pr.size();
    for(int i=0; i<33; i++){
        // int left = i;
        // ll value = 0;
        int right = i+max_len;
        if(right > sz) break;
        ll value = S[right] - S[i];
        while(right < sz){
            if(value + pr[right] > n) break;
            value += pr[right];
            if(isPrime(value)){
                int aux = right-i+1;
                if(aux >= max_len){
                    if(aux > max_len){
                        max_len = aux;
                        ans = value;
                    }
                    else
                        ans = min(ans, value);
                }
            }
            right++;
        }
    }
    cout << ans << " " << max_len << '\n';
}

int main() {
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}
