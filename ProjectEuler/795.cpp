#include <iostream>
#include <vector>
#include <map>
using namespace std;

using ll = long long;
#define mp make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define N 6172842

int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll fastexp_m(ll x, ll y, ll p){
	ll ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x)%p;
		y = y>>1;
		x = (x*x)%p;
	}
	return ans%p;
}

bool check_composite(ll n, ll a, ll d, int s){
	ll x = fastexp_m(a,d,n);
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
//int gsf[N];
vi primes;
vii primes_factors[N];
void sieve(){
	for(int i=2; i<N; i++){
		if(!lpf[i]){
            primes.pb(i);
			lpf[i] = i;
			for(ll j=2LL*i; j<N; j+=i)
				lpf[j] = i;
		}
	}
}

void fill(){
    for(int i=2; i<N; i++){
        if(lpf[i] == i)
            primes_factors[i].pb(mp(i, 1));
        else{
            int next_factor = i/lpf[i];
            primes_factors[i] = primes_factors[next_factor];
            int sz = primes_factors[i].size();
            if(primes_factors[i][sz-1].first == lpf[i])
                primes_factors[i][sz-1].second++;
            else
                primes_factors[i].pb(mp(lpf[i], 1));
        }
    }
}

ll get_greatest_sq_factor(vii &a){
	ll ans = 1;
	for(int i=0; i<a.size(); i++)
		ans *= fastexp(a[i].first, a[i].second/2);
	return ans;
}


ll h(int p, int a, int c1, int a1, int c2, int a2){
	// n = p^a
	// k = c1*p1^a1
	// d = c2*p2^a2
	vii ans;
	if(c1 + c2 > 2)
		ans.push_back(make_pair(2, (c1+c2)/2));
	ans.push_back(make_pair(p, a1+a2));
	ll n = 2*fastexp(p, a);
	ll k = c1*fastexp(p, a1);
	ll d = c2*fastexp(p, a2);
	ll number = 1LL*k*d;
	ll gsf = get_greatest_sq_factor(ans);
	ll rest = number/(gsf*gsf);
	// rest * j^2 = n/gsf ^ 2
	// i^2 = gsf * rest^2 * m^2
	// m = sqrt(i/(sqrt(gsf)*rest))
	// i = rest*m*sqrt(gsf)
	ll total = n/(1LL*gsf*rest);
	// 4*i^2 = gsf * rest^2 * m^2
	// i = rest*m*sqrt(gsf)/2
	// gst*rest^2*(2,4,6,8,...)^2 = 4*i^2
	ll even = 0;
	if(gsf%2 == 0 or rest%2 == 0)
		even = total;
	else
		even = (n/2)/(gsf*rest);
	return 2*even - total;
}

ll g(int p, int a){
	ll ans = 0;
	ll n = 2*fastexp(p, a);
	for(int i=0; i<2*a+2; i++){
		int c = 1 + i%2;
		int alpha = i/2;
		ll k = c*fastexp(p, alpha);
		// k = c*p^alpha
		ll aux = 0;
		aux += h(p, a, c, alpha, 1, 0);
		if(alpha < a){
			aux += -h(p, a, c, alpha, 1, 1);
		}
		if(c == 1){
			aux += -h(p, a, c, alpha, 2, 0);
			if(alpha < a){
				aux += h(p, a, c, alpha, 2, 1);
			}
		}
		ans += aux*k;
	}
	return ans;
}

// p = prime^alpha
// prme != 2
// g(2^n) = 2^(n+(n+1)/2-1) - 2^n + 2^(n+n/2) - 2^(n-1)
// g(4) = 6
// g(8) = 20

ll M[N];

// n = 2*p
// g(n) = p, 2p, 3p, 4p, ..., kp = -p*((n/p)+1/2) = -p*(1)
// g(n) = 2, 4, 6, 8, 10, 12, ..., (n/2)*2 = 2*(n/2 - n/2p) = 2*(p-1)
// g(n) = 2p, 4p, 6p, 8p, ..., (n/2p)*2p = 2p*(n/2p) = 2p*(1)
// g(n) = n - (n/2p) - (n/2 - n/2p) - ((n/p)+1/2) = -(p - 1)
// g(n) = -p+2p-2+2p-(p-1) = 2p-1 = n - 1
void preCalculated(){
	for(int i=1; i<primes.size(); i++){
		if(primes[i] >= N) break;
		M[primes[i]] = 2*primes[i]-1;
	}
	for(int i=1; i<primes.size(); i++){
		if(1LL*primes[i]*primes[i] >= N) break;
		M[primes[i]*primes[i]] = 1LL*primes[i]*(1LL*primes[i]*(primes[i]+1) - 1);
	}
	for(int i=1; i<primes.size(); i++){
		ll current = 1LL*primes[i]*primes[i]*primes[i];
		int alpha = 3;
		if(current >= N) break;
		while(current < N){
			M[current] = g(primes[i], alpha);
			current *= primes[i];
			alpha++;
		}
	}
}

ll get_g(int x){
	if(x == 1) return -1;
	if(x%2 == 0){
        int aux_n = __builtin_ctz(x);
		ll ans = (1LL<<(aux_n + aux_n/2));
		ans -= (1LL<<(aux_n - 1));
		ans -= (1LL<<aux_n);
		ans += (1LL<<(aux_n + (aux_n+1)/2 - 1));
		x /= (1<<aux_n);
        if(x == 1) return ans;
		else{
			//cout << x << " ";
			if(isPrime(x)) return ans*(2*x-1);
            vii factorization = primes_factors[x];
			for(int i=0; i<factorization.size(); i++)
				ans *= M[fastexp(factorization[i].first, factorization[i].second)];
			return ans;
		}
	}
	else return -x;
}

int main(){
    sieve();
    fill();
	preCalculated();
	ll ans = 0;
	for(int i=1; i<=12345678; i++)
		ans += get_g(i);
	cout << ans;
	//g(p) = -(p-1)
	//g(p^a) = -(p^a-1)
	return 0;
}
//153, 1225, 4753, 29161, ... = n*n*(2n^2-1) = 17, 45, 97, 
//33, 145, 385, 1441, 2353 = n*(n*(n+1) - 1)
//5, 9, 13, 21, 25 = 2*n-1
//3, 5, 7, 11, 13

//g(2^n * p1 * p2 ... ) = g(p1)*g(p2)*g(p3)*...*(g(2^n)*(m*(m+1) - 1));
// m = p1*p2*p3...

// g(2^n) * G(p1^a1) * G(p2^a2) * ...