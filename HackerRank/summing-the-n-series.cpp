#include <bits/stdc++.h>
using namespace std;
long long prim = 1000000007;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long n;
        cin >> n;
        cout << (1LL*(n%prim)*(n%prim))%prim<<'\n';
    }
    return 0;
}
