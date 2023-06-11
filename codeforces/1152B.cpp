#include <bits/stdc++.h>
using namespace std;
bool test(long long x){
    if(x==0) return true;
    int bt = floor(1.0*log2(1.0*x))+1;
    for(int i=0; i<bt; i++){
        if(x&1 == 1){
            x = x>>1;
        }
        else return false;
    }
    return true;
}
int main(){
    long long pot2[40];
    pot2[0] = 1;
    for(int i=1; i<40; i++) pot2[i] = 1LL*pot2[i-1]*2;
    for(int i=0; i<40; i++) pot2[i] = pot2[i]-1;
    long long a;
    cin >> a;
    if(test(a)){
        cout << 0;
        return 0;
    }
    vector <int> answ;
    for(int i=1; i<=40; i++){
        if(i%2 == 1){
            for(int j=0; j<40; j++){
                if(pot2[j] > a){
                    a = a^pot2[j];
                    answ.push_back(j);
                    break;
                }
            }
        }
        else a=a+1;
        if(test(a)){
            cout << i << '\n';
            for(int j=0; j<answ.size(); j++) cout << answ[j] << " ";
            return 0;
        }
    }
    return 0;
}
