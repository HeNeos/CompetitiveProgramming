#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n, U, R, D, L; cin >> n >> U >> R >> D >> L;
        bool flag = true;
        for(int i=0; i<16; i++){
            int u = U, r = R, d = D, l = L;
            if(i & 1){u--; l--;}
            if(i & 2){l--; d--;}
            if(i & 4){d--; r--;}
            if(i & 8){r--; u--;}
            if(min(u, min(r, min(d , l))) >= 0 and max(u, max(r, max(d , l))) <= n-2){
                cout << "YES";
                flag = false;
                break;
            }
        }
        if(flag) cout << "NO";
        cout << '\n';
    }
    return 0;
}