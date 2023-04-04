#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n, f; cin >> n >> f;
        map <int, int> m;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            m[x]++;
        }
    
        long long ans = 0;
        for(auto v: m){
            int value = v.first;
            int count = v.second;
            while(value%f == 0){
                value /= f;
                int c = m[value];
                ans += 1LL*c*count;
            }
            ans += 1LL*(count)*(count-1)/2;
        }
        cout << ans << '\n';
    }
	return 0;
}

