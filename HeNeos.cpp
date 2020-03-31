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
int TestMillerRabin[9] = {2,3,5,7,11,13,17,19,23};
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
bool isPrime(ll p){
	bool flag = true;
	if(p<=1) return false;
	for(int i=0; i<9; i++){
		int value = TestMillerRabin[i];
		if(value >= p) break;
		if(fastexp(value,p,p) != value){
			flag = false;
			break;
		}
	}
	return flag;
}

int main(){
	return 0;
}
