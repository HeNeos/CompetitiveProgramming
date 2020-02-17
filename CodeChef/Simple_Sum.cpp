#include <bits/stdc++.h>
using namespace std;
int prim[100005];
long long fastexp(long long a, long long b){
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2 == 0){
		long long aux = fastexp(a,b/2);
		return 1LL*aux*aux;
	}
	long long aux = fastexp(a,(b-1)/2);
	return 1LL*a*aux*aux;
}
vector <int> rp;
void lpf(){
    for(int i=0; i<100005; i++) prim[i] = 0;
    for(int i=2; i<100005; i++){
        if(!prim[i]){
            for(int j=1; 1LL*j*i<100005; j++){
                if(!prim[1LL*i*j]) prim[1LL*i*j] = i;
            }
        }
    }
	for(int i=2; i<100005; i++){
		if(prim[i] == i) rp.push_back(i);
	}
}
int mobius[100005];
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<100005; i++){
        if(prim[i] == i) mobius[i] = -1;
        else{
            if(prim[i/prim[i]] == prim[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/prim[i]];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lpf();
    cmob();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> divisors;
		for(int i=1; i*i<=n; i++){
			if(n%i == 0){
				divisors.push_back(i);
				if(i != n/i) divisors.push_back(n/i);
			}
		}
		long long answ = 0;
		for(int i=0; i<divisors.size(); i++){
			int answ2 = n/divisors[i];
			int act = n/divisors[i];
			int cc = prim[act];
			while(act > 1){
				cc = prim[act];
				while(prim[act] == cc){
					act = act/cc;
				}
				answ2 = answ2 - (answ2)/cc;
			}
			answ = answ + answ2*(n/divisors[i]);
		}
		cout << answ << '\n';
	}
	return 0;
}
