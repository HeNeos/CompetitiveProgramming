#include <iostream>
using namespace std;

int solve(int x){
    return __builtin_ctz(x);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            ans += solve(x);
        }
        cout << ans << '\n';
    }
    return 0;
}