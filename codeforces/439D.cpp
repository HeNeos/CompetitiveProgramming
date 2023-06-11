#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int m;
    long long answ = 0;
    cin >> n >> m;
    int arrn[n];
    int arrm[m];
    for(int i=0; i<n; i++) cin >> arrn[i];
    for(int i=0; i<m; i++) cin >> arrm[i];
    sort(arrn,arrn+n);
    sort(arrm,arrm+m,greater<int>());
    for(int i=0; i<min(n,m) && arrn[i]<arrm[i]; i++){
        answ += arrm[i]-arrn[i]; 
    }
    cout<<answ;
    return 0;
}
