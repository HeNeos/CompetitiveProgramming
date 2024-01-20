#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000000005

// int lpf[N];
// void sieve(){
//     for(int i=2; i<N; i++){
//         if(!lpf[i]){
//             lpf[i] = i;
//             for(ll j=1LL*i*i; j<N; j+=i){
//                 if(lpf[j] == 0) lpf[j] = i;
//             }
//         }
//     }
// }

vector <int> factors(int n){
    vector <int> ans;
    for(int i=2; 1LL*i*i<=n; i++){
        while(n%i == 0){
            ans.push_back(i);
            n /= i;
        }
    }
    if(n != 1) ans.push_back(n);
    // while(n != 1){
    //     int d = lpf[n];
    //     while(n%d == 0){
    //         n /= d;
    //         ans.push_back(d);
    //     }
    // }
    return ans;
}

int main(){
    // sieve();
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case #" << _ << ": ";
        int p; cin >> p;
        vector <int> f = factors(p);
        ll s = 0;
        for(auto v: f) s += v;
        if(s <= 41){
            int c = f.size() + (41-s);
            cout << c << " ";
            for(int i=0; i<41-s; i++) cout << "1 ";
            for(auto v: f) cout << v << " ";
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}