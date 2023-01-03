#include <bits/stdc++.h>
using namespace std;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

void solve(){
    
}

int main(){
    FIFO;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            ans ^= x;
            cnt += (x == 1);    
        }
        if(cnt == n) cout << ((n&1)?"Brother":"John"); 
        else{
            if(ans) cout << "John";
            else cout << "Brother";
        }
        cout << '\n';
    }
    return 0;
}