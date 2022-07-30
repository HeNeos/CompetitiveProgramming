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
int numb[500005];
vector <int> cantpr;
void sieve(int n){
	bool ispr[n+1];
	for(int i=0; i<=n; i++) ispr[i] = true;
	for(ll i=2; i<=n; i++){
		if(ispr[i]){
			cantpr.pb(i);
			for(ll j=1LL*i*i; j<=n; j+=i) ispr[j] = false;
		}
	}
}
int main(){
	int n;
	cin >> n;
	if(n<=3){
		for(int i=1; i<n; i++) cout << 1 << " ";
		return 0;
	}
	for(int i=1; i<=n; i++) numb[i] = 1;
	vector <int> answ;
	sieve(n);
	answ.pb(n/2);
	numb[2*(n/2)] = 0;
	int ccpr = cantpr.size()+1;
	int posgcd = n/2;
	for(int i=1; i<=n-ccpr-1; i++){
		ll aux = posgcd;
		int cont = 0;
		ll lessaux = 0;
		while(aux<=n){
			if(numb[aux] == 1){
				cont++;
				lessaux = aux;
			}
			aux += posgcd;
		}
		if(cont>=2){
			answ.pb(posgcd);
			numb[lessaux] = 0;
		}
		else{
			posgcd--;
			answ.pb(posgcd);
			ll auxi = posgcd;
			ll what = 0;
			while(auxi <= n){
				if(numb[auxi] == 1) what = auxi;
				auxi += posgcd;
			}
			numb[what] = 0;
		}
	}
	for(int i=2; i<=ccpr; i++) answ.pb(1);
	for(int i=answ.size()-1; i>=0; i--) cout << answ[i] << " ";
	return 0;
}
