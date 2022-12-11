#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int diff = arr[n-1] - arr[0];
        if(diff == 0){
            long long ans = 1LL*n*(n-1);
            cout << ans << '\n';
        }
        else{
            long long ans = 1;
            int m = 0; int M = 0;
            for(int i=0; i<n; i++){
                if(arr[i] == arr[0]) m++;
                if(arr[i] == arr[n-1]) M++;
            }
            ans *= m;
            ans *= M;
            cout << 2LL*ans << '\n';
        }
    }
    return 0;
}
