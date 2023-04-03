#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        if(x == 1){
            cout << 3 << '\n';
            continue;
        }
        int p = __builtin_ctz(x);
        int y = (1<<p);
        if(x == y) cout << y+1 << '\n';
        else cout << y << '\n';
    }
    return 0;
}