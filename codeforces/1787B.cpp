#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <pair <int, int> > get_prime_factors(int n){
    vector <pair <int, int> > ans;
    for(int i=2; 1LL*i*i <=n; i++){
        if(n%i == 0){
            int p = i;
            int c = 0;
            while(n%p == 0){
                n /= p;
                c++;
            }
            ans.push_back(make_pair(p, c));
        }
    }
    if(n != 1) ans.push_back(make_pair(n, 1));
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <pair <int, int> > f = get_prime_factors(n);
        ll ans = 0;
        while(true){
            bool br = true;
            ll value = 1;
            for(int i=0; i<f.size(); i++){
                if(f[i].second != 0){
                    value *= f[i].first;
                    f[i].second--;
                    br = false;
                }
            }
            if(br) break;
            ans += value;
        }
        cout << ans << '\n';
    }
    return 0;
}