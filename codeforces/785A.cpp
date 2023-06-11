#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int answ = 0;
    for (int i = 1; i <= n; i++){
        string poly;
        cin >> poly;
        if(poly[0] == 'T') answ += 4; 
        if(poly[0] == 'C') answ += 6;
        if(poly[0] == 'O') answ += 8;
        if(poly[0] == 'D') answ += 12;
        if(poly[0] == 'I') answ += 20;
    }
    cout << answ;
    return 0;
}
