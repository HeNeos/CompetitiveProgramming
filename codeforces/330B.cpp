#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    bool aux[n+1];
    for(int i=1; i<=n; i++) aux[i] = true;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        aux[a] = false;
        aux[b] = false;
    }
    for(int i=1; i<=n; i++){
        if(aux[i]){
            cout << n-1 << '\n';
            for(int j=1; j<=n; j++){
                if(i!=j) cout << i << " " << j << '\n';
            }
            return 0;
        }
    }
    return 0;
}
