#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 1000000000000
#define N 1000000

map <ll, bool> m;

void solve(){
    for(int base=2; base<=N; base++){
        ll amount = base+1;
        for(int len=2;; len++){
            amount *= base;
            amount++;
            if(amount >= MAXN) break;
            m[amount] = true;
        }
    }
}

ll calculate_sum(){
    ll ans = 1;
    for(auto v: m) ans += v.first;
    return ans;
}

int main(){
    solve();
    cout << calculate_sum() << '\n';
    return 0;
}