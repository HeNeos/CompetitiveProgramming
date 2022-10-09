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
        int n;
        cin >> n;
        n--;
        int div3 = n/3;
        int div5 = n/5;
        int div15 = n/15;
        cout << 3*(1LL*div3*(div3+1))/2+5*(1LL*div5*(div5+1))/2-15*(1LL*div15*(div15+1))/2 << '\n';
    }
    return 0;
}
