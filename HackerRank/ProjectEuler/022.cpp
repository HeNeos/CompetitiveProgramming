#include <bits/stdc++.h>
using namespace std;

map <string, int> m;

int main() {
    int n; cin >> n;
    vector <string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        int score = 0;
        for(int j=0; j<v[i].size(); j++)
            score += (int)(v[i][j] - 'A' + 1);
        m[v[i]] = score*(i+1);
    }
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        cout << m[s] << '\n';
    }
    return 0;
}
