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

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        int skill = 0;
        int last = -1;
        for(int i=0; i<n; i++){
            if(a[i] -skill < 1) continue;
            if(a[i] - skill == 1) skill++;
            else{
                ans += (a[i] - skill - 1);
                skill++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}