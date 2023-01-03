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

#define N 100008
int candies[N];
int prefsum[N];
int rep[N];
int main(){
    int c, n;
    while(true){
        cin >> c >> n;
        if(c == 0 and n == 0) break;
        for(int i=0; i<n; i++) cin >> candies[i];
        for(int i=0; i<n+3; i++) rep[i] = -1;
        prefsum[0] = 0;
        rep[0] = 0;
        for(int i=1; i<=n; i++){
            prefsum[i] = (prefsum[i-1] + candies[i-1])%c;
            if(rep[prefsum[i]] != -1){
                for(int j=rep[prefsum[i]]+1; j<=i; j++){
                    cout << j;
                    if(j != i) cout << " ";
                }
                cout << '\n';
                break;
            }
            rep[prefsum[i]] = i;
        }
    }
    return 0;
}
