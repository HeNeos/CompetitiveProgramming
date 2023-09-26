#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        int s, d, k;
        cin >> s >> d >> k;
        int buns = 2*s + 2*d;
        int patty = s + 2*d;
        int cheese = s + 2*d;
        cout << "Case #" << _ << ": ";
        if(buns >= k+1 && patty >= k && cheese >= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}