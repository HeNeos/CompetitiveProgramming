#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100000005
#define limit 1000005

vector <int> pi_sieve(limit);

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
    phi_cache[values] = ans;
    return ans;
}

map <ll,ll> pi_cache;

ll pi(ll x){
    if(x < limit) return pi_sieve[x];
    
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

int main(){
    primes = prime_sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long ans = 0;
        for(int i=0; i<primes.size(); i++){
            int p = primes[i];
            if(1LL*p*p >= n) break;
            ans += pi((n-1)/p);
            ans -= pi(p-1);
        }
        cout << ans << '\n';
    }
    return 0;
}
