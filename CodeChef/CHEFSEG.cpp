#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll finden(ll k){
    if(k == 0) return 1;
    if(k == 1) return 2;
    
    return 2LL*finden(k/2);
}
ll finnum(ll k){
    if(k == 0) return 0;
    if(k == 1) return 1;
    if(k%2 == 0) return 2LL*finnum(k/2)-1;
    else return 2LL*finnum((k-1)/2)+1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, k;
        cin >> x >> k;
        ll den = finden(k);
        ll num = finnum(k);
        double ans = (double)(((double)(num))/den);
        ans = ans*x;
        printf("%.12lf\n",ans);
    }
    return 0;
}