#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > dp;

int solve(vector <int> &a1, vector <int> &a2, int p1, int p2){
    if(p1 >= a1.size() or p2 >= a2.size()) return 0;
    if(dp[p1][p2] != -1) return dp[p1][p2];

    if(a1[p1] == a2[p2])
        dp[p1][p2] = 1 + solve(a1, a2, p1+1, p2+1);
    else
        dp[p1][p2] = max(solve(a1, a2, p1+1, p2), solve(a1, a2, p1, p2+1));
    return dp[p1][p2];
}

int main(){
    int n1, n2;
    int c = 0;
    while(true){
        c++;
        cin >> n1 >> n2;
        if(n1 == 0 and n2 == 0) break;
        vector <int> a1(n1);
        vector <int> a2(n2);
        for(int i=0; i<n1; i++)
            cin >> a1[i];
        for(int i=0; i<n2; i++)
            cin >> a2[i];
        
        dp.clear();
        dp.resize(n1);
        for(int i=0; i<n1; i++){
            dp[i].resize(n2);
            for(int j=0; j<n2; j++) dp[i][j] = -1;
        }
        printf("Twin Towers #%d\n", c);
        printf("Number of Tiles : %d\n\n", solve(a1, a2, 0, 0));
    }
    return 0;
}