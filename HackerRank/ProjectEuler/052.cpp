#include <bits/stdc++.h>
using namespace std;

vector <int> digits(int x){
    vector <int> ans(10);
    while(x > 0){
        ans[x%10]++;
        x /= 10;
    }
    return ans;
}

bool match(vector <int> &a, vector <int> &b){
    for(int i=0; i<10; i++)
        if(a[i] != b[i]) return false;
    return true;
}

int main() {
    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++){
        vector <int> d = digits(i);
        bool found = true;
        for(int j=2*i; j<=k*i; j+=i){
           vector <int> aux = digits(j);
           if(!match(d, aux)){
               found = false;
               break;
           }
        }
        if(found){
            for(int j=i; j<=k*i; j+=i) cout << j << " ";
            cout << '\n';
        }
    }
    return 0;
}
