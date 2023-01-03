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

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = (1LL*x*x)%p;
    }
    return ans%p;
}

#define N 100005
int main(){
    FIFO;
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll aux = (1LL*k*k-3LL*k+3)%MOD;
        if(n == 1) cout << k << '\n';
        else{
            ll ans = 1;
            if(!(n&1)){
                ans = (1LL*k*k-k)%MOD;
                n -= 2;
                ans = (1LL*ans*fastexp(aux,n/2,MOD))%MOD;
            }
            else{
                ans = (1LL*k*k-k)%MOD;
                n -= 2;
                if(n == 1) ans = (1LL*ans*(k-2))%MOD;
                else{
                    ans = (ans*fastexp(aux,n/2,MOD))%MOD;
                    ans = (1LL*ans*(k-2))%MOD;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
