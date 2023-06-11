#include <bits/stdc++.h>
using namespace std;
bool test(int money, int cost){
    if(money >= cost) return true;
    else return false;
}
int main() {
    int n;
    int days;
    cin >> n;
    int prec[n];
    for(int i=0; i<n; i++){
        cin >> prec[i];
    }
    cin >> days;
    int din[days];
    for(int i=0; i<days; i++){
        cin >> din[i];
    }
    sort(prec, prec+n);
    for(int i=0; i<days; i++){
        int lo = 0;
        int hi = n-1;
        while(lo<hi){
            int med = (hi + lo + 1)/2;
            if(test(din[i],prec[med])){
                lo = med; 
            }
            else hi = med - 1;
        }
        if(din[i] >= prec[0]) cout << lo + 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
