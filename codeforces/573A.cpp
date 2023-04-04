#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    set <int> s;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        while(x%3 == 0) x /= 3;
        while(x%2 == 0) x /= 2;
        s.insert(x);
    }
    if(s.size() == 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

