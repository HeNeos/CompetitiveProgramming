#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define N 10000005

vector <int> pi_sieve(N);
vector <int> primes;
map <pair <ll,ll>, ll> phi_cache;
map <ll,ll> pi_cache;

pair <ll,ll> limits(ll n){
    double nn = (double)(n);
    double ln = log(nn);
    double lln = log(ln);
  
    ll hig = (ll)(nn*(ln+lln-1+(lln-2)/ln-(lln*lln-6*lln+10.273)/(2*ln*ln)));
    ll low = (ll)(nn*(ln+lln-1+(lln-2)/ln -(lln*lln-6*lln+11.847)/(2*ln*ln)));

    low = max(low, (ll)(ln*n));
    low = max(low, 2LL);
    if(n < 8009824){
        hig = (ll)(1.25*nn*ln)+1;
        if(n < 15) hig = hig + (ll)(2.1*nn);
    }
    return make_pair(low,hig); //reference in https://docserv.uni-duesseldorf.de/servlets/DerivateServlet/Derivate-28284/pdfa-1b.pdf
}

void primeSieve(){
    bitset <N> sieve;
    for(int i=2; i<N; i++){
        if(!sieve[i]){
            pi_sieve[i] = pi_sieve[i-1] + 1;
            primes.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) sieve[j] = 1;
        }
        else pi_sieve[i] = pi_sieve[i-1];
    }
}

ll phi(ll x, ll a){
    pair <ll,ll> values = make_pair(x,a);
    if(phi_cache.find(values) != phi_cache.end()) return phi_cache[values];      
    if(a == 1) return (x+1)/2;
    ll ans = phi(x, a-1) - phi(x/primes[a-1], a-1);
    phi_cache[values] = ans;
    return ans;
}

ll pi(ll x){
    if(x < N) return pi_sieve[x];

    if(pi_cache.find(x) != pi_cache.end()) return pi_cache[x];

    int a = pi((int)(pow(x,1.0/4)));
    int b = pi((int)(sqrt(x)));
    int c = pi((int)(pow(x,1.0/3)));

    ll ans = phi(x,a) + 1LL*(b+a-2)*(b-a+1)/2;

    for(int i=a+1; i<b+1; i++){
        ll w = x/primes[i-1];
        ans -= pi(w);
        if(i <= c){
            ll b_i = pi((int)(sqrt(w)));
            for(int j=i; j<b_i+1; j++)
                ans = ans - pi(w/primes[j-1]) + j - 1;
        }
    }
    pi_cache[x] = ans;
    return ans;
}

ll nPrime(ll n){
    if(n <= primes.size()) return primes[n-1];
    pair <ll, ll> LIMITS = limits(n);
    ll lo = LIMITS.first;
    ll hi = LIMITS.second;

    while(lo < hi){
        ll me = lo + (hi-lo)/2;
        ll test = pi(me);
        if(test >= n) hi = me;
        else lo = me + 1;
    }
    return lo;
}


int main(){
    FIFO;
    primeSieve();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << nPrime(pi(n-1)) << '\n';
        pi_cache.clear(); phi_cache.clear();
    }
    return 0;
}