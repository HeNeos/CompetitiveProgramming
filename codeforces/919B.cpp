#include<bits/stdc++.h>
using namespace std;
int check(int numb){
    int sum=0;
    while(numb){
        sum += numb%10;
        numb /= 10;
    }
    return sum;
}
int main(){
    int k;
    int answ=1;
    cin >> k;
    while(k){
        if(check(answ)==10){
            answ += 9;
            k--;
        }
        else answ++;
    }
    cout << answ-9;
    return 0;
}
