#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 2200005
int divisor[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(divisor[i] == 0){
            for(ll j=i; j<N; j+=i){
                divisor[j]++;
            }
        }
    }
}


int main() {
    sieve();
    int n, k; cin >> n >> k;
    vector <int> ans;
    for(int i=2; i<=n; i++){
        bool found = true;
        for(int j=i; j<i+k; j++)
            found &= (divisor[j] == k);
        if(found)
            ans.push_back(i);
    }
    for(auto v: ans)
        cout << v << '\n';
    return 0;
}
