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

#define N 55
int main(){
    int t;
    cin >> t;
    while(t--){
        int s,c,k;
        cin >> s >> c >> k;
        ll ans[N];
        ans[0] = s;
        for(int i=1; i<N; i++){
            ans[i] = max((s-i),0);
            if(c-i>=0) ans[i]++;
        }
        ll count = 0;
        for(int i=0; i<N; i++){
            if(i == 0){
                if(ans[i] >= k) count += 3;
                continue;
            }
            if(ans[i] >= k) count = count + (1LL<<i);
        }
        cout << count << '\n';
    }
    return 0;
}
