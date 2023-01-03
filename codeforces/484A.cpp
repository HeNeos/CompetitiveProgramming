#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
        long long l, r; cin >> l >> r;
        bitset <64> L(l); bitset<64> R(r);
        for(int i=63; i>=0; i--){
            if(R[i] > L[i]){
                for(int j=i-1; j>=0; j--)
                    L[j] = 1;
                break;
            }
        }
        if(R.count() > L.count())
            cout << R.to_ullong() << '\n';
        else
            cout << L.to_ullong() << '\n';
    }
    return 0;
}