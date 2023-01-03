#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n; int w[2*n];
    for(int i=0; i<2*n; i++)
        cin >> w[i];


    sort(w, w+2*n);

    int maxi = (1<<30);
    for(int i=0; i<2*n; i++){
        for(int j=i+1; j<2*n; j++){
            int aux = 0; bool taked = false; int p = 0;
            for(int k=0; k<2*n; k++){
                if(k == i or k == j) continue;
                if(!taked){
                    taked = true;
                    p = w[k];
                }
                else{
                    taked = false;
                    aux += abs(w[k]-p);
                }
            }
            maxi = min(maxi, aux);
        }
    }
    cout << maxi;
    return 0;
}