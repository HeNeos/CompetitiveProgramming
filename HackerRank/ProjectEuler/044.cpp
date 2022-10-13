#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set <ll> s;

void fill(){
    for(int i=1; i<1500000; i++){
        ll v = 1LL*i*(3*i-1)/2;
        s.insert(v);
    }
}

int main() {
    fill();
    int n, k; cin >> n >> k;
    for(int i=k+1; i<=n; i++){
        ll v1 = 1LL*(i-k)*(3*(i-k)-1)/2;
        //ll v2 = 1LL*(i+k)*(3*(i+k)-1)/2;
        ll v = 1LL*i*(3*i-1)/2;
        if(s.find(v-v1) != s.end()){
            cout << v << '\n';
            continue;
        }
        if(s.find(v+v1) != s.end()){
            cout << v << '\n';
            continue;
        }
    }
    return 0;
}
