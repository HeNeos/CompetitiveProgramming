#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    bitset <32> N(n);
    int b = N.count();
    if(k > n or k < b) cout << "NO";
    else{
        cout << "YES\n";
        vector <int> a(32);
        for(int i=31; i>=0; i--) a[i] = N[i];
        int p = 31;
        while(b != k){
            if(a[p] + b >= k){
                a[p] -= (k-b);
                a[p-1] += 2*(k-b); 
                b = k;
                break;
            }
            else{
                b += a[p];
                a[p-1] += 2*a[p];
                a[p] = 0; 
            }
            p--;
        }
        for(int i=0; i<32; i++){
            for(int j=0; j<a[i]; j++) cout << (1<<i) << " ";
        }
    }
    return 0;
}