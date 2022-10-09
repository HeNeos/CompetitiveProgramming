#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define mods 1000000009
#define modhash1 1000000009
#define modhash2 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = (1LL*x*x)%p;
    }
    return ans%p;
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
ll invmod(ll x, ll p){
    return fastexp(x,p-2,p)%p;
}
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

#define N 1000005
bitset <N> pr;
vector <int> primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(pr[i] == 0){
            primes.pb(i);
            for(ll j = 1LL*i*i; j<N; j+=i) pr[j] = 1;
        }
    }   
}

int main(){
    FIFO;
    sieve();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <ll> div;
        for(int i=1; 1LL*i*i<=n; i++){
            if(n%i == 0){
                div.pb(i);
                if(n/i != i) div.pb(n/i);
            }
        }
        sort(div.begin(), div.end());
        for(int i=div.size()-1; i>=0; i--){
            if(isPrime(div[i])){
                cout << div[i] << '\n';
                break;        
            }
        }
    }
    return 0;
}
