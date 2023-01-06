#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int m_pos = -1;
        int M_pos = -1;
        int m = INT_MAX;
        int M = INT_MIN;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            if(x > M){
                M = x;
                M_pos = i+1;
            }
            if(x < m){
                m = x;
                m_pos = i+1;
            }
        }
        cout << min(m_pos, M_pos) << " " << max(m_pos, M_pos) << endl;
    }
    return 0;
}