#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int odd = 0;
        int even = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]%2 == 0) even++;
            else odd++;
        }
        if(odd > 0)
            cout << even << '\n';
        else{
            int min_p = INT_MAX;
            for(int i=0; i<n; i++){
                int p = __builtin_ctz(a[i]);
                min_p = min(p, min_p);
            }
            cout << min_p + (even-1) << '\n';
        }
    }
    return 0;
}