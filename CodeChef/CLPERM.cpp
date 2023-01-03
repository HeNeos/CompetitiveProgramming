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
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int taked[k];
        ll sum = 0;
        int loose = INT_MAX;
        ll sumofall = 0;
        for(int i=0; i<k; i++){
            cin >> taked[i];
        }
        sort(taked,taked+k);
        for(int i=0; i<k; i++){
            sumofall += taked[i];
            if(i == 0) sum = (1LL*taked[i]*(taked[i]-1))/2;
            else{
                int aux = taked[i]-taked[i-1]-1;
                sum = sum + 1LL*taked[i-1]*aux + (1LL*aux*(aux+1))/2;//taked[i-1]+1, taked[i-1]+2 ... taked[i]-1 = taked[i-1]+(taked[i]-taked[i.1]-1)
            }
            if(taked[i] > sum) loose = min(loose,taked[i]);
        }
        if(loose != INT_MAX){
            if(loose%2 == 0){
                cout << "Mom\n";
            }
            else cout << "Chef\n";
            continue;
        }
        else{
            ll what = (1LL*n*(n+1))/2 - sumofall;
            if(what%2 == 0){
                cout << "Chef\n";
            }
            else{
                cout << "Mom\n";
            }
            continue;
        }
    }
    return 0;
}
