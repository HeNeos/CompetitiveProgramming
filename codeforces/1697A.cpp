#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int m, n; cin >> n >> m;
        int s = 0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            s += x;
        }
        cout << max(0, s-m) << '\n';
    }
    return 0;
}