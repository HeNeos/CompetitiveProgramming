#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k;
    cin >> k;
    cin >> s;
    int acum[s.size()+1];
    acum[0] = 0;
    for(int i=0; i<s.size(); i++){
        acum[i+1] = acum[i];
        if(s[i] == '1') acum[i+1]++;
    }
    long long ans = 0;
    map <int, int> m;
    m[0] = 1;
    for(int i=1; i<=s.size(); i++){
        int current = acum[i];
        ans += m[current-k];
        m[current]++;
    }
    cout << ans << '\n';
    return 0;
}