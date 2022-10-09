#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 500005

int divs[N];
void sieve(){
    divs[1] = 1;
    for(int i=2; i<N; i++){
        for(ll j=i; j<N; j+=i){
            divs[j] += i;
        }
    }
    for(int i=2; i<N; i++){
        divs[i] -= i;
        divs[i]++;
    }
}
vector <int> ans;
void fill(){
    for(int i=2; i<100005; i++){
        if(divs[divs[i]] == i && i != divs[i])
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
}

int main() {
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll s = 0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] >= n) break;
            s += ans[i];
        }
        cout << s << '\n';
    }
    return 0;
}
