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
        ll n, k;
        cin >> n >> k;
        ll ans = n-n/k;
        int count = 0;
        ll aux = 1LL*k*k;
        while(true){
            if(n/aux == 0) break;
            if(count%2 == 0) ans = ans+n/aux;
            else ans = ans-n/aux;
            aux = 1LL*aux*k;
            count++;
        }    
        cout << ans << '\n';
    }
    return 0;
}
