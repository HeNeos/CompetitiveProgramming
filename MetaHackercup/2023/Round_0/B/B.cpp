#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        int r, c; cin >> r >> c;
        int a, b; cin >> a >> b;
        cout << "Case #" << _ << ": ";
        if(r > c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
