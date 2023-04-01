#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        bool found = false;
        for(int i=0; i<n; i++){
            if(i+1 >= a[i]){
                found = true;
                break;
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}