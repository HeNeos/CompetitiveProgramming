#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector <int> d;
        for(int i=1; 1LL*i*i<=n; i++){
            if(n%i == 0){
                d.push_back(i);
                if(i != n/i)
                    d.push_back(n/i);
            }
        }
        int ans = 0;
        for(int i=0; i<d.size(); i++){
            for(int j=i; j<d.size(); j++){
                if(1LL*d[i]*d[j]/__gcd(d[i],d[j]) == n){
                    ans++;
                }
            }
        }
        cout << n << " " << ans << '\n';
    }
    return 0;
}