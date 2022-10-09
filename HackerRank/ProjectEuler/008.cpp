#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string num;
        cin >> num;
        ll ans = 0;
        for(int start=0; start+k<num.size(); start++){
            ll product = 1;
            for(int len=0; len<k; len++){
                int d = (int)(num[start+len] - '0');
                product *= d;
            }
            ans = max(ans, product);
        }
        cout << ans << '\n';
    }
    return 0;
}
