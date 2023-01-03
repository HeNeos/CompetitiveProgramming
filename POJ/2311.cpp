#include <iostream>
#include <set>
#include <iterator>
#include <bitset>
using namespace std;

int W, H;
int dp[205][205];
int solve(int w, int h){
    if(dp[w][h] != -1) return dp[w][h];
    bitset <405> states;
    for(int i=2; i<w-1; i++)
        states[solve(i, h)^solve(w-i, h)] = 1;
    for(int i=2; i<h-1; i++)
        states[solve(w, i)^solve(w, h-i)] = 1;
    int n = 0;
    
    for(n = 0; n < 405; n++){
        if(!states[n]) break;
    }
    dp[w][h] = n;
    return dp[w][h];
}

int main(){
    for(int i=0; i<205; i++){
        for(int j=0; j<205; j++) dp[i][j] = -1;
    }
    
    while(cin >> W >> H){
        cout << (solve(W, H)?"WIN":"LOSE") << '\n';
    }
    return 0;
}