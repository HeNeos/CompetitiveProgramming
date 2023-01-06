#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t; cin >> n >> t;
    string s = to_string(t);
    while(s.size() < n)
        s += "0";
    if(s.size() == n) cout << s;
    else cout << "-1";
    cout << endl;
    return 0;
}