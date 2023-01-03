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

ll A[64], n, m;
int C[64][64];

void fill(){
    C[0][0] = 1;
    for (int i = 1; i < 64; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }    
}

ll solve(ll s, int i, int choose)  {
    if(choose > m || choose+i+1< m || s > 1LL*A[i]*(i+1)) return 0;
    ll ans = 0;
      for(; i >= 0; i--){
          if(A[i] > s){
              if(choose + 1 + i >= m) ans += C[i][m - (choose + 1)];
          } 
          else break;
      }
      for (; i > 0; i--) ans += solve(s-A[i], i-1, choose+1);
      return ans;
}   
int main(){
    FIFO;
    fill();
    int t;
    cin >> t;
    for(int kk = 1; kk<=t; kk++){
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A, A + n);
        ll ans = 0;
        for(int i = 2; i < n; i++){
            for(int j = i-1; j > 0; j--){
                ans += solve(A[i]-A[j], j-1, 2);
            }
        }
        cout << "Case " << kk << ": " << ans << '\n';
    }
    return 0;
}