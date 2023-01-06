#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char c; cin >> c;
        string s; cin >> s;
        int pos = -1;
        bool allC = true;
        for(int i=0; i<n; i++){
            if(s[i] != c) allC = false;
            else if(i >= n/2) pos = i;
        }
        if(allC) cout << "0\n";
        else{
            if(pos != -1){
                cout << "1\n";
                cout << pos + 1 << '\n';
            }
            else{
                cout << "2\n";
                cout << n << " " << n-1 << '\n';
            }
        }
    }
    return 0;
}