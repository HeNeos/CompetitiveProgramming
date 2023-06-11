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
ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = (1LL*x*x)%p;
    }
    return ans%p;
}
ll invmod(ll x, ll p){
    return fastexp(x,p-2,p)%p;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int d, m;
        cin >> d >> m;
        ll answ = 0;
        ll auxd = d;
        int cntb = 0;
        while(auxd > 0){
            auxd = auxd/2;
            cntb++;
        }
        int n =cntb; //cantidad de bits de d
        ll dp[n+1][n+1];
        // dp[i][j] = Cantidad de formas al escoger numeros hasta de i bits, j veces
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++) dp[i][j] = 0;
        }    
        for(int i=1; i<n; i++) dp[i][1] = fastexp(2,i,m)-1;
        dp[n][1] = d;
        for(int i=2; i<n; i++){
            for(int j=2; j<=i; j++){
                dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1]*fastexp(2,i-1,m))%m)%m;
            }
        }
        for(int i=2; i<=n; i++) dp[n][i] = (dp[n-1][i] + (dp[n-1][i-1]*(d-fastexp(2,n-1,m)+1))%m+m)%m;
        for(int i=1; i<=n; i++) answ = (answ+dp[n][i])%m;
        cout << answ << '\n';
    }
    return 0;
}
