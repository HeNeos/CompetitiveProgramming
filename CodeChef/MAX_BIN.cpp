#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        for(int i=0; i<k-1; i++) s += "0";
        if(s[0] == '0') s[0] = '1';
        else s += "0";
        cout << s << '\n';
    }
    return 0;
}
