#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 10000005

ll fastexp(ll x, ll y){
	ll ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x);
		y = y>>1;
		x = (x*x);
	}
	return ans;
}

int lpf[N];
void sieve(){
    for(int i=2; i<N; i++){
		if(!lpf[i]){
			lpf[i] = i;
			for(ll j=1LL*i*i; j<N; j+=i){
				if(lpf[j] == 0) lpf[j] = i;
			}
		}
	}
}

void get_prime_factorization(int n, vector <pair<int, int> > &f){
    while(n != 1){
        int prime_factor = lpf[n];
        int exponent = 0;
        while(n%prime_factor == 0){
            exponent++;
            n /= prime_factor;
        }
        f.push_back({prime_factor, exponent});
    }
}

ll solve(vector <pair <int, int> > &f){
    ll ans = 1;
    for(int i=0; i<f.size(); i++){
        ll p = f[i].first;
        ll a = f[i].second;
        // 1 + p^2-p^1 + p^4-p^3 + ... + p^2a - p^2a-1 
        // 1 + p(p-1) + p^3(p-1) + ... + p^2a-1(p-1)
        // 1 + (p-1)*(p)*(1+p^2+...+p^(2a-2)) = 1 + (p-1)*p*(p^2a-1)/(p^2-1)
        ll value = (fastexp(p, 2*a) - 1)/(p + 1);
        value *= p; value++;
        ans *= value;
    }
    return ans;
}

int main(){
    FIFO;
    sieve();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <pair <int, int> > factors;
        get_prime_factorization(n, factors);
        cout << solve(factors) << '\n';
    }
    return 0;
}
