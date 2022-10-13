#include <bits/stdc++.h>
using namespace std;

int factorial[10];
void fill(){
    factorial[0] = 1;
    for(int i=1; i<10; i++) factorial[i] = factorial[i-1]*i;
}

int S(int x){
    int ans = 0;
    while(x>0){
        ans += factorial[x%10];
        x /= 10;
    }
    return ans;
}

int main() {
    fill();
    int n; cin >> n;
    int ans = 0;
    for(int i=10; i<n; i++){
        if(S(i)%i == 0)
            ans += i;
    }
    cout << ans << '\n';
    return 0;
}
