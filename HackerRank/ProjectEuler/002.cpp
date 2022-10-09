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

#define N 85
int main(){
    FIFO;
    ll fib[N];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<N; i++)
        fib[i] = fib[i-1]+fib[i-2];
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        for(int i=2; i<N; i++){
            if(fib[i] <= n){
                if(fib[i]%2 == 0) ans+=fib[i];
            }
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}
