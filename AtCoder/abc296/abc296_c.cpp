#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    map <long long, int> m;
    for(int i=0; i<n; i++){
        long long v;
        cin >> v;
        m[v]++;
        if(m.find(v-x) != m.end() || m.find(x+v) != m.end()){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
