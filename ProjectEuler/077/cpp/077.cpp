#include <bits/stdc++.h>
using namespace std;
#define N 1005
using ll = long long;

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

vector <int> a(N);

int main(){
    sieve();
    a[0] = 1;
    for(auto prime: p){
    	vector <int> a_cp = a;
	    for(int i=N-1; i>=0; i--){
	    	if(i < prime) break;
	    	ll s = 0;
	    	for(int j=1;; j++){
	    		if(i-j*prime < 0) break;
	    		s += a_cp[i-j*prime];
	    	}
	    	a[i] += s;
	    }
    }
    for(int i=1; i<N; i++){
    	if(a[i] >= 5000){
    		cout << i << '\n';
    		break;
    	}
    }
    return 0;
}
