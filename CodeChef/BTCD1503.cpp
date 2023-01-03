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
    ll x = fastexp(a,d,n);
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
#define N 100000
ll pr[N];
vector <ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(pr[i] == 0){
            pr[i] = i;
            primes.pb(i);
            for(ll j=1LL*i*i; j<N; j+=i){
                if(pr[j] == 0) pr[j] = i;
            }
        }
    }
}
int mb[N];
void cmb(){
    mb[1] = 1;
    for(int i=2; i<N; i++){
        if(pr[i] == i) mb[i] = -1;
        else{
            if(pr[i/pr[i]] == pr[i]) mb[i] = 0;
            else mb[i] = -1*mb[i/pr[i]];
        }
    }
}
ll n;
int mobius(vector <pair<ll,int> > &divpr, ll a){
    if(a == 1) return 1;
    if(isPrime(a)) return -1;
    
    if(a > n/a){
        ll nn = n/a;
        vector <pair <int,int> > divisors;
        for(int i=0; i<primes.size(); i++){
            if(primes[i] > nn) break;
            if(nn%primes[i] == 0){
                divisors.pb({primes[i],0});
                while(nn%primes[i] == 0){
                    nn = nn/primes[i];
                    divisors[divisors.size()-1].second++;
                }
            }
        }
        if(divisors.size() == 0){
            int amount = 0;
            for(int i=0; i<divpr.size(); i++){
                if(divpr[i].second >= 2) return 0;
                if(divpr[i].second != 0) amount++;
            }
            if(amount%2 == 0) return 1;
            else return -1;
        }
        sort(divisors.begin(), divisors.end());
        int amount = 0;
        for(int i=0, j=0; i<divpr.size(); i++){
            int gg = divpr[i].second;
            if(j<divisors.size() && divisors[j].first == divpr[i].first){
                gg -= divisors[j].second;
                j++;
            }
            if(gg >= 2) return 0;
            if(gg != 0) amount++;
        }
        if(amount%2 == 0) return 1;
        else return -1;
        
    }
    else return mb[a];
}
ll invv = 166666668;
int main(){
    sieve();
    cmb();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            cout << 0 << '\n';
            continue;
        }
        vector <ll> div;
        for(ll i=1; 1LL*i*i <= n; i++){
            if(n%i == 0){
                div.pb(i);
                if(n/i != i) div.pb(n/i);
            }
        }
        vector <pair<ll,int> > divpr;
        ll auxn = n;
        for(int i=0; i<primes.size(); i++){
            if(auxn < primes[i]) break;
            if(auxn%primes[i] == 0){
                divpr.pb({primes[i],0});
                while(auxn%primes[i] == 0){
                    auxn = auxn/primes[i];
                    divpr[divpr.size()-1].second++; 
                }
            }
        }
        if(auxn > 1) divpr.pb({auxn,1});
        sort(divpr.begin(),divpr.end());
        
        ll ans = 0;
        for(int i=0; i<div.size(); i++){
            int mu = mobius(divpr,div[i]);
            if(mu == 0) continue;
            ll aux = (1LL*div[i]*div[i])%MOD;
            aux = (1LL*aux*n/div[i])%MOD;
            aux = (1LL*aux*(n/div[i]+1))%MOD;
            aux = (1LL*aux*(2LL*n/div[i]+1))%MOD;
            aux = (1LL*aux*invv)%MOD;
            aux = (aux*mu);
            ans = (ans+aux)%MOD;
        }
        ans = (ans+MOD)%MOD;
        cout << ans << '\n';
    }
    return 0;
}
