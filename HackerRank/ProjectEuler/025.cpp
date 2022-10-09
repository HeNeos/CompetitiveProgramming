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

#define N 30000
double phi = 2/((double)(sqrt(5)+1));
int main(){
    FIFO;
    ll aux[45];
    aux[0] = 0;
    aux[1] = 1;
    for(int i=2; i<45; i++) aux[i] = aux[i-1]+aux[i-2];
    double fib[N];
    for(int i=0; i<45; i++) fib[i] = log10((double)(aux[i]));
    for(int i=45; i<N; i++) // log(a+b) = log(a) + log(1+b/a)
        fib[i] = fib[i-1] + log10(1+phi);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<N; i++){
            if(fib[i] >= n-1){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
