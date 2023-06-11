#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int k;
    long long aux;
    int cont0 = 0;
    int contd = 0;
    vector <int> dig;
    cin >> n >> k;
    aux = n;
    while(aux>=10){
        dig.push_back(aux%10);
        aux /= 10;
    }
    dig.push_back(aux);
    for(int i=0; i<dig.size(); i++){
        if(dig[i] == 0) cont0++;
        else contd++;
        if(cont0 == k){
            cout << contd;
            return 0;
        }
    }
    if(cont0 < k) cout<<dig.size()-1;
    return 0;
}
