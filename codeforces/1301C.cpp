#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int zeros = n-m;
        int groups = m+1;
        int k = zeros/groups;
        long long ans = (1LL*n*(n+1))/2 - (1LL*k*(k+1))/2 * groups - (k+1)*(zeros%groups);
        cout << ans << '\n';
    }
    return 0;
}