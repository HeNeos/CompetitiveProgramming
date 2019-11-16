#include <bits/stdc++.h>
using namespace std;
int m;
int n;
int k;
int brok;
int posx[250005];
int posy[250005];
int tim[250005];
long long matr[505][505];
bool test(int T){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) matr[i][j]=0;
    }
    for(int i=1; i<=brok; i++){
        if(tim[i]<=T) matr[posx[i]][posy[i]]=1;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) matr[i][j]+=matr[i-1][j]+matr[i][j-1]-matr[i-1][j-1];
    }
    for(int i=k; i<=m; i++){
        for(int j=k; j<=n; j++){
            if(matr[i][j]-matr[i-k][j]-matr[i][j-k]+matr[i-k][j-k]==k*k) return true;
        }
    }
    return false;
}
int main(){
    cin >> m >> n >> k >> brok;
    for(int i=1; i<=brok; i++){
    	cin >> posx[i] >> posy[i] >> tim[i];
    }
    long long answ = -1;
    long long low = 0;
    long long high = 1e9;
    while(low < high){
        long long med = low+(high-low)/2;
        if(test(med) == true){
            high = med;
        }
        else low = med + 1;
    }
    if(test(low)) cout << low;
    else cout << -1;
    return 0;
}
