#include <bits/stdc++.h>
using namespace std;

int res[30];

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<30; j++){
            if(a[i] & (1<<j)) res[j]++;
        }
    }
    pair <int, int> ans = {-1, -1};
    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=0; j<30; j++){
            if(a[i] & (1<<j)){
                if(res[j] == 1) tmp ^= (1<<j);
            }
        }
        if(ans < make_pair(tmp, i))
            ans = make_pair(tmp, i);
    }
    cout << a[ans.second] << " ";
    for(int i=0; i<n; i++){
        if(i != ans.second) cout << a[i] << " ";
    }
    return 0;
}