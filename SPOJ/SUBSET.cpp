#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define N 100005
#define FIFO ios::sync_with_stdio(false)

using namespace std;

map <long long, bool>R[1<<20];
long long sum[1<<20], a[20];
vector <long long> L[1<<10];

int main(){

    FIFO;

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)cin >> a[i];
    
    
    for(int i = 1, j; i < (1<<n); i++){
        
        j = 31 - __builtin_clz(i);
        sum[i] = sum[i ^ (1<<j)] + a[j];
    }
    
    int n1 = n/2, n2 = n - n1, ans = 0;
    long long diff;
    
    for(int i = 0; i < (1<<n1); i++){

        bool balancedLeft = false;
        for(int j = i; j > 0; j = (j - 1)&i){

            diff = abs(sum[i] - 2 * sum[j]);
            L[i].pb(diff);
            if(diff == 0)balancedLeft = true;
        }
        sort(all(L[i]));
        L[i].resize(unique(all(L[i]))-L[i].begin());
        if(balancedLeft)ans++;
    }
    
    
    for(int i = 0; i < (1<<n2); i++){
        
        bool balancedRight = false;
        for(int j = i; j > 0; j = (j - 1)&i){

            diff = abs(sum[i<<n1] - 2 * sum[j<<n1]);
            R[i][diff] = true;
            if(diff == 0)balancedRight = true;
        }
        if(balancedRight)ans++;
    }
    
    for(int l = 0; l < (1<<n1); l++){
        for(int r = 0; r < (1<<n2); r++){
            bool found = false;
            for(int j=0; j<L[l].size(); j++){
                diff = L[l][j];
                if(R[r].find(diff) != R[r].end()) found = true;
            }
            if(found)ans++;
        }
    }
    
    cout << ans << endl;

}