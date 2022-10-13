#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SQ sqrt(3.0)

vector <int> t;
vector <int> p;

int test(int x, ll value){
    int v = floor(SQ*x);
    ll n_v = 1LL*v*(v+1)/2;
    if(n_v == value) return v;
    else return -1;
}

void fill(){
    for(int i=1; i<6203350; i++){
        ll v = 1LL*i*(3*i-1)/2;
        int x = test(i, v);
        if(x != -1){
            p.push_back(i);
            t.push_back(x);
        }
    }
}

int main() {
    // n*(n+1) = m*(3m-1)
    // 3m^2 - 3m - (n^2+n) = 0
    // m = 3 + sqrt(9 + 12n^2 + 12n) / 6 aprox n/sqrt(3)
    // n = -1 + sqrt(1 + 12m^2 - 4m)/2 aprox msqrt(3) - 1
    fill();
    ll n; cin >> n;
    int a, b; cin >> a >> b;
    if(max(a, b) == 6){
        for(int i=0; i<p.size(); i+=2){
            ll v = 1LL*p[i]*(3*p[i]-1)/2;
            if(v >= n) break;
            cout << v << '\n';
        }
    }
    else{
        for(int i=0; i<p.size(); i++){
            ll v = 1LL*p[i]*(3*p[i]-1)/2;
            if(v >= n) break;
            cout << v << '\n';
        }
    }
    return 0;
}
// 1 - 1
// 20 - 12 = 1.6666
// 285 - 165 = 1.727272
// 3976 - 2296 = 1.73170
// 55385 - 31977 = 
// 771420 - 445380 = 
// 10744501 - 6203341 =

// 165 - 143 = 1.1538
// 31977 - 27693 = 1.1546
// 