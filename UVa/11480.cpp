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
    int n;
    int cont = 0;
    while(true){
        cont++;
        cin >> n;
        if(n==0) break;
        n-=3;
        cout << "Case " << cont << ": " << (1LL*n*n+6)/12 << '\n';
    } 

    //i+i+k+i+k+p = N
    //N = 3*i+2*k+p
    // N = 5
    // N-3 = 2*k+p -> (N-4)/2
    // N-6 = 2*k+p -> (N-7)/2
    // N-9 = 2*k+p -> (N-10)/2
    // ... -> (N-3*j-1)/2
    // N = 4
    //
    //
    
    return 0;
}

