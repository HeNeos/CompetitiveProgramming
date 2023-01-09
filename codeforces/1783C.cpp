#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int arr[n];
        int auxi[n];
        for(int i=0; i<n; i++){
            int x; cin >> x;
            arr[i] = x;
            auxi[i] = x;
        }
        sort(arr, arr+n);
        vector <int> aux(n);
        for(int i=0; i<n; i++)
            aux[i] = i;
        int acum = 0;
        int prev_acum = 0;
        int c = 0;
        bool fix = true;
        for(int i=0; i<n; i++){
            if(acum + arr[i] <= m){
                prev_acum = acum;
                acum += arr[i];
                c++;
            }
            else{
                if(i > 0 && fix && c < n && prev_acum + auxi[c] <= m)
                    fix = false;
                break;
            }
        }
        if(fix) cout << n-c+1<<"\n";
        else cout << n-c << '\n';
    }
    return 0;
}