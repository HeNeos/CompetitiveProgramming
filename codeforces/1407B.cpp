#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int last = 0;
        vector <bool> took(n, false);
        for(int i=0; i<n; i++){
            int pos = -1;
            int maxi = -1;
            for(int j=0; j<n; j++){
                if(!took[j] && __gcd(arr[j], last) > maxi){
                    maxi = __gcd(arr[j], last);
                    pos = j;
                }
            }
            last = __gcd(last, arr[pos]);
            took[pos] = true;
            cout << arr[pos] << " ";
        }
        cout << '\n';
    }
    return 0;
}