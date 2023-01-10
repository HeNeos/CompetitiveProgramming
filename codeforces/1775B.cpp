#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <vector <int> > c(n);
        map <int, int> m;
        for(int i=0; i<n; i++){
            int k; cin >> k;
            for(int j=0; j<k; j++){
                int x; cin >> x;
                c[i].push_back(x);
                m[x]++;
            }
        }
        bool ans = false;
        for(int i=0; i<n; i++){
            bool found = true;
            for(int j=0; j<c[i].size(); j++){
                if(m[c[i][j]] <= 1){
                    found = false;
                    break;
                }
            }
            if(found){
                ans = true;
                break;
            }
        }
        if(ans) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
    return 0;
}