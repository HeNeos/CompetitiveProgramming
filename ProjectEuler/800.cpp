#include <bits/stdc++.h>
using ll = long long;

using namespace std;

#define N 20000000
#define M 800800

bitset <N> primes;
vector <int> p;
void sieve(){
	for(int i=2; i<N; i++){
		if(!primes[i]){
			p.push_back(i);
			for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
		}
	}
}

int main(){
	sieve();
	ll ans = 0;
	for(int i=0; i<p.size()-1; i++){
		double limit = M*log2(M);
		int lo = i;
		int hi = p.size()-1;
		while(lo < hi){
			int me = lo + (hi - lo + 1)/2;
			if(p[me]*log2(p[i]) + p[i]*log2(p[me]) <= limit)
				lo = me;
			else
				hi = me-1;
		}
		int aux = max(0, lo - i);
        if(aux == 0) break;
        ans += aux;
	}
	cout << ans << '\n';
	return 0;
}