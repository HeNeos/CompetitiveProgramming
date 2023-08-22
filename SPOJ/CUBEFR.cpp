#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000
#define MAX 1000000

bitset <N> primes;
vector <int> p;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            p.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

bool s[MAX+1];
int acum[MAX+1];
void fill(){
    for(auto v: p){
        long long power = 1LL*v*v*v;
        if(power > MAX) break;
        for(int i=1; power*i<=MAX; i++)
            s[power*i] = true;
    }
    for(int i=1; i<=MAX; i++)
        acum[i] = acum[i-1] + s[i];
}

int main(){
    sieve();
    fill();
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case " << _ << ": ";
        int n; cin >> n;
        if(s[n]) cout << "Not Cube Free";
        else{
            int ans = n;
            ans -= acum[n];
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}
