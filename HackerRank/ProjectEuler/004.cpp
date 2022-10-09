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

int main(){
    FIFO;
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <int> ans;
        for(int i = 110; i<=999; i+=11){
            for(int j=100; j<=999; j++){
                if(i*j < n){
                    ans.pb(i*j);
                }
            }
        }
        int fans = -1;
        for(int i=0; i<ans.size(); i++){
            string s = to_string(ans[i]);
            bool flag = true;
            for(int j=0; j<s.size(); j++){
                if(s[j] != s[s.size()-j-1]) flag = false;
            }
            if(flag) fans = max(fans,ans[i]);
        }
        cout << fans << '\n';
    }
    return 0;
}
