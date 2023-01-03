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

ll tr[100000];
int main(){
    for(int i=0; i<100000; i++) tr[i] = (1LL*i*(i+1))/2;
    int t;
    cin >> t;
    string s;
    for(int kk=1; kk<=t; kk++){
        getline(cin,s);
        int n;
        cin >> n;
        if(kk != 1) cout << '\n';
        n = abs(n);
        if(n == 0){
            cout << 3 << '\n';
            continue;
        }
        int pos = -1;
        for(int i=0; i<1000000; i++){
            if(tr[i] <= n and n < tr[i+1]){
                pos = i;
                break;
            }
        }
        if(n == tr[pos]){
            cout << pos << '\n';
        }
        else{
            if(pos%2 == 1){
                if((n-tr[pos])%2 == 1) cout << pos+2 << '\n';
                else cout << pos+1 << '\n';
            }
            else{
                if((n-tr[pos])%2 == 1) cout << pos+1 << '\n';
                else cout << pos+3 << '\n';
            }
        }
    }
    return 0;
}
