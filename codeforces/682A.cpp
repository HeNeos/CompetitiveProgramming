#include <iostream>
using namespace std;
using ll = long long;
int main(){
    int n, m; cin >> n >> m;
    ll ans = 0;
    for(int i=1; i<5; i++){
        int x = (n-i+5)/5;
        int y = (m-(5-i)+5)/5;
        ans += 1LL*x*y;
    }
    ans += 1LL*(n/5)*(m/5);
    cout << ans << '\n';
    return 0;
}