#include <bits/stdc++.h>
using namespace std;
int timer[105][105];
int solv(int ch1, int ch2){
    if(ch1 <= 0 or ch2 <= 0) return 0;
        if(ch1 == 1 and ch2 == 1) return 0;
    if(timer[ch1][ch2] != -1) return timer[ch1][ch2];
    if(timer[ch2][ch1] != -1){
        timer[ch1][ch2] = timer[ch2][ch1];
        return timer[ch1][ch2];
    }    
    timer[ch1][ch2] = 1+max(solv(ch1+1,ch2-2),solv(ch1-2,ch2+1));
    return timer[ch1][ch2];
}
int main(){
    for(int i=0; i<104; i++){
        for(int j=0; j<104; j++) timer[i][j] = -1;
    }
    int a1, a2;
    cin >> a1 >> a2;
    cout << solv(a1,a2);
    return 0;
}