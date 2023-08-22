#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 50005

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

bool m[N];
void fill(){
    for(int i=0; i<p.size(); i++){
        for(int j=i+1; j<p.size(); j++){
            int v = p[i] + p[j];
            if(v >= N) break;
            m[v] = true;
        }
    }
}


int main(){
    FIFO;
    sieve();
    fill();
    int q; cin >> q;
    for(int _=1; _<=q; _++){
        int n; cin >> n;
        cout << "Case " << _ << ": ";
        if(n == 1 or n == 4 or n == 6){
            cout << -1 << '\n';
            continue;
        }
        if(!primes[n]) cout << 1 << '\n';
        else{
            if(!m[n]) cout << 3;
            else cout << 2;
            cout << '\n';
        }
    }
    return 0;
}
