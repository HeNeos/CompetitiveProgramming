#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;
        if(x%k == 0)
            cout << 0 << " " << k << '\n';
        else{
            int l = x/k;
            int r = x/k+1;
            int q = x%l;
            int p = (x-q*(l+1))/l;
            cout << p << " " << q << '\n'; 
        }
    }
}