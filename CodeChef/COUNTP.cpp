#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int s = 0;
        bool odd = false;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            s += x; s %= 2;
            if(x&1) odd = true;
        }
        if(odd && s%2 == 0) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
