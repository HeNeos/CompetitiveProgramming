#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    int k;
    int cont = 0;
    int difsldir;
    cin >> n >> m >> k;
    int sldir[m+1];
    for(int i = 0; i <= m; i++){
        cin >> sldir[i];
    }
    for(int i = 0; i < m; i++){
        difsldir = sldir[i]^sldir[m];
        int bitdiff = 0;
        for(int j = 0; j < n ; j++){
            if((difsldir>>j)&1){
                bitdiff++;
            }
        }
        if(bitdiff<=k){
            cont++;
        }
    }
    cout << cont <<"\n";
}
