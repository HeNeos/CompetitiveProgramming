#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_bouncy(int x){
    vector <int> dig;
    while(x){
        dig.push_back(x%10);
        x /= 10;
    }
    int sz = dig.size();
    bool increase = true;
    bool decrease = true;
    for(int i=sz-1; i>0; i--){
        if(dig[i] > dig[i-1]) increase = false;
        if(dig[i] < dig[i-1]) decrease = false;
    }
    return (!increase && !decrease);
}

int main(){
    int count = 0;
    for(int i=1;; i++){
        if(is_bouncy(i)) count++;
        if(count*100 >= 99*i){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}