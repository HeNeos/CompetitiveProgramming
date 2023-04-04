#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int pos[n+1];
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) pos[a[i]] = i;
        int m = n/2 + 1;
        int M = (n+1)/2;
        int ans = n/2;
        while(m != 1){
            m--; M++;
            if(pos[m] > pos[m+1] || pos[M-1] > pos[M]) break;
            ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}