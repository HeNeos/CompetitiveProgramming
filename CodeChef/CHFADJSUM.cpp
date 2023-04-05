#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        map <int, int> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a+n);
        int z = a[n-1] + a[n-2];
        if(a[n-1] == a[n-2]){
            if(n >= 2*m[a[n-1]]-1) cout << "YES";
            else cout << "NO";
        }
        else{
            if(m[a[n-2]] + 1 < n) cout << "YES";
            else cout << "NO";
        }
        cout << '\n';
    }
	return 0;
}