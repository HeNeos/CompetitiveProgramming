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
    ll dp[70];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<70; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    int n;
    int cont = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        else{
            cont++;
            cout << "Case " << cont << ": " << dp[n-1] << '\n';
        }
    }
    return 0;
}
