#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> arr;
    vector <int> zeropos;
    arr.push_back(0);
    zeropos.push_back(-1e9);
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
        if(a==0) zeropos.push_back(i);
    }
    for(int i=1; i<=n; i++){
        int answ = 1e8;
        auto aux = lower_bound(zeropos.begin(), zeropos.end(), i) - zeropos.begin(); 
        if(aux == 0) answ = abs(zeropos[aux]-i);
        else{
            if(aux == n+1 && n > 1) answ = abs(zeropos[aux-1]-i);
            answ = min(abs(zeropos[aux]-i), abs(zeropos[aux-1]-i));
        }
        cout << answ << " ";
    }
    return 0;
}
