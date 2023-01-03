#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    if(n%2 != 0){
        cout << 0; return 0;
    }
    int ans = (n-4)/2 +1;
    if(n%4 == 0) ans--;
    cout << ans/2;
    return 0;
}