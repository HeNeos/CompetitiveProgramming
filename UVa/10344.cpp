#include <bits/stdc++.h>
using namespace std;
int numb[5];
bool answ(int value, int count){
    if(count==5) return value==23;
    int num=numb[count];
    return answ(value+num, count+1) || answ(value-num, count+1) || answ(value*num, count+1);
}
int main(){
    while(true){
        int sum=0;
        for(int i=0; i<5; i++){
            cin >> numb[i];
            sum += numb[i];
        }
        if(sum == 0) break;
        sort(numb,numb+5);
        do{
            if(answ(numb[0],1)){
                cout<<"Possible\n";
                goto exit;
            }
        }while(next_permutation(numb,numb+5));
        cout<<"Impossible\n";
        exit:;
    }
    return 0;
}
