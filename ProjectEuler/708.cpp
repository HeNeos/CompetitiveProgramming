#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 100000000000000
const long long limit = 10000005;
const long long cache_limit = 50000000;

map <ll, ll> cache[48][670000];
map <ll, ll> pi_div;

vector <int> pi_sieve(limit);

int ceil_power(ll n, ll m){
    double p = pow(n, 1.0/m);
    int x = floor(p);
    if(pow(x+1, m) <= n) return x+1;
    else return x;
}

vector <int> prime_sieve(){
    bitset <limit> sieve;
    vector <int> ans;
    for(int i=2; i<limit; i++){
        if(!sieve[i]){
            pi_sieve[i] = pi_sieve[i-1] + 1;
            ans.push_back(i);
            for(ll j=1LL*i*i; j<limit; j+=i) sieve[j] = 1;
        }
        else pi_sieve[i] = pi_sieve[i-1];
    }
    return ans;
}

vector <int> primes;

map <pair <ll,ll>, ll> phi_cache;

ll phi(ll x, ll a){
    pair <ll,ll> values = {x,a};
    if(phi_cache.find(values) != phi_cache.end()) return phi_cache[values];
    if(a == 1) return (x+1)/2;
    ll ans = phi(x, a-1) - phi(x/primes[a-1], a-1);
    if(phi_cache.size() < cache_limit) phi_cache[values] = ans;
    return ans;
}

map <ll,ll> pi_cache;

ll pi(ll x){
    if(x < limit) return pi_sieve[x];

    if(pi_div.find(x) != pi_div.end()) return pi_div[x];
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
    if(pi_cache.size() < cache_limit) pi_cache[x] = ans;
    return ans;
}

ll Pi(ll n, int m, int it){
    ll ans = 0;
    if(cache[m][it].find(n) != cache[m][it].end()){
        ans = cache[m][it][n];
        return ans;
    }
    if(m == 2){
        for(int i=it; i<pi(ceil_power(n, 2)); i++) ans += pi(n/primes[i])-(i+1)+1;
    }
    else{
        for(int i=it; i<pi(ceil_power(n, m)); i++) ans += Pi(n/primes[i], m-1, i);
    }
    cache[m][it][n] = ans;
    return ans;
}


ll solve(ll n){
    int m = log2(n);
    ll ans = 2*pi(n);
    for(int i=2; i<=m; i++){
        ll out = Pi(n, i, 0);
        cout << i << " " << out << '\n';
        ans += out * (1LL<<i);
    }
    return ans;
}


int main(){
    FIFO;
    primes = prime_sieve();
    ll n = N;
    for(int i=0; i<10000000; i++){
        ll x; cin >> x;
        pi_div[N/(i+1)] = x;
    }
    cout << 1 + solve(n) << '\n';
}