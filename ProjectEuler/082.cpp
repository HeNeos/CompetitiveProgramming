#include <bits/stdc++.h>
using namespace std;
#define N 80

vector <vector <int> > m(N);

vector <int> split(string s){
    int sz = s.size();
    string cur =  "";
    vector <int> ans;
    for(int i=0; i<sz; i++){
        if(s[i] == ','){
            ans.push_back(stoi(cur));
            cur = "";
        }
        else cur += s[i];
    }
    ans.push_back(stoi(cur));
    return ans;
}

int solve(int r){
    int ans = INT_MAX;
    int current_col[N];
    int past_col[N];
    memset(current_col, 0, sizeof current_col);
    memset(past_col, 0, sizeof past_col);

    past_col[r] = m[r][0];

    for(int i=r-1; i>=0; i--)
        past_col[i] = past_col[i+1] + m[i][0];
    for(int i=r+1; i<N; i++)
        past_col[i] = past_col[i-1] + m[i][0];

    for(int col=1; col<N; col++){
        for(int row=0; row<N; row++){
            current_col[row] = past_col[row] + m[row][col];
        }
        for(int i=0; i<40; i++){
	        current_col[0] = min(current_col[0], m[0][col] + current_col[1]);
	        for(int row=1; row<N-1; row++){
	            current_col[row] = min(current_col[row], m[row][col] + current_col[row-1]);
	            current_col[row] = min(current_col[row], m[row][col] + current_col[row+1]);
	        }
	        current_col[N-1] = min(current_col[N-1], m[N-1][col] + current_col[N-2]);
        }
        for(int row=0; row<N; row++)
            past_col[row] = current_col[row];
    }
    for(int i=0; i<N; i++){
        ans = min(ans, current_col[i]);
    }
    return ans;
}

int main(){
    string s;
    for(int i=0; i<N; i++){
        cin >> s;
        m[i] = split(s);
    }
    int ans = INT_MAX;
    for(int i=0; i<N; i++){
	    ans = min(ans, solve(i));
    }
    cout << ans << '\n';
    return 0;
}