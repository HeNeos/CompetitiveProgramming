#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int answ=0;
    long long l;
    long long r;
    int diff;
    cin >> n >> l >> r >> diff;
    long long numb[n];
    for(int i=0; i<n; i++) cin >> numb[i];
    for(long long mask=0; mask<(1<<n); mask++){
        long long maxim=-1;
        long long minim=10000000;
        long long dif=0;
        for(int k=0; k<n; k++){
            if((mask>>k)&1==1){
                dif += numb[k];
                maxim=max(maxim,numb[k]);
                minim=min(minim,numb[k]);
            }
        }
        if(l<=dif && dif<=r && (maxim-minim)>=diff) answ++;
    }
    cout<<answ;
    return 0;
}
