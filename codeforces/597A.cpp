#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = ((b-(b%k + k)%k)-(a+(k-a%k)%k))/k+1;
    cout << ans << '\n';
    return 0;
}