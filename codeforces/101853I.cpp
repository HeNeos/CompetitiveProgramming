#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, d; cin >> a >> b >> d;
        unsigned long long ans = d;
        ans *= d;
        bool decimal = false;
        if(ans%2 == 1){
            ans--;
            decimal = true;
        }
        ans /= 2;
        cout << ans;
        if(decimal) cout << ".5";
        cout << '\n';
    }
}