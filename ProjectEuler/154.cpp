#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 200000

int f_2[N+5];
int f_5[N+5];

void fill(){
    for(int i=2; i<N+5; i++){
        int copy = i;
        while(copy > 1){
            copy /= 2;
            f_2[i] += copy;
        }
        copy = i;
        while(copy > 1){
            copy /= 5;
            f_5[i] += copy;
        }
    }
}


pair <int, int> pascal_value(int i, int j){
    pair <int, int> ans;
    ans.first = f_2[i] - f_2[j] - f_2[i-j];
    ans.second = f_5[i] - f_5[j] - f_5[i-j];
    return ans;
}

bool pascal_pyramid(int n, int i, int j){
    pair <int, int> ans1 = pascal_value(i, j);
    pair <int, int> ans2 = pascal_value(n, i);
    if(ans1.first + ans2.first >= 12 and ans1.second + ans2.second >= 12)
        return true;
    else
        return false;
}


int main(){
    fill();

    ll ans = 0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(pascal_pyramid(N, i, j)) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}