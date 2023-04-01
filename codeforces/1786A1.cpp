#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int current = 0;
        int a = 0;
        int b = 0;
        int step = 0;
        while(n){
            int res = min(n, current);
            n -= res;
            if(step%4 == 0 or step%4 == 1){
                a += res;
            }
            else{
                b += res;
            }
            current++;
            step++;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}