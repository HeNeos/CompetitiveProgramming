#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cont[1030];
void preprocess(vector <ll> &arr){
    for(int i=0; i<1030; i++) cont[i] = 0;
    for(int i=0; i<arr.size(); i++){
        string s = to_string(arr[i]);
        int aux = 0;
        for(int j=0; j<s.size(); j++)
            aux = aux | (1<<((int)(s[j]-'0')));
        cont[aux]++;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        preprocess(arr);
        ll ans = 0;
        for(int i=1; i<1024; i++)
            ans += (1LL*cont[i]*(cont[i]-1))/2;
        
        for(int i=1; i<1024; i++){
            for(int j=i+1; j<1024; j++){
                if(i&j)
                    ans += 1LL*cont[i]*cont[j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}