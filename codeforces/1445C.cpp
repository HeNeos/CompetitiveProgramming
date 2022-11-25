#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastexp(ll x, ll y){
	ll ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x);
		y = y>>1;
		x = (x*x);
	}
	return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll p, q; cin >> p >> q;
        ll ans = 1;
        if(p%q != 0) ans = p;
        vector <pair <ll, int> > a;
        for(ll i=2; i*i <= q; i++){
        	if(q%i == 0){
        		int c = 0;
        		while(q%i == 0){
        			q /= i;
        			c++;
        		}
        		a.push_back(make_pair(i, c));
        	}
        }
        if(q != 1) a.push_back(make_pair(q, 1));
		for(int i=0; i<a.size(); i++){
            int c = 0;
            ll aux_p = p;
            while(aux_p % a[i].first == 0){
            	c++;
            	aux_p /= a[i].first;
            }
            int c_diff = (c - a[i].second + 1);
            ans = max(ans, p/fastexp(a[i].first, c_diff));
        }
        cout << ans << '\n';
    }
    return 0;
}