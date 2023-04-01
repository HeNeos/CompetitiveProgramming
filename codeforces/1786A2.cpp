#include <bits/stdc++.h>
using namespace std;

// n cards from color
pair <int, int> get_colors(int color, int n){
    // color, 1-color, color, 1-color...
    // 2 -> {1, 1}
    // 1 -> {1, }
    // 3 -> {2, 1}
    pair <int, int> ans;
    if(n%2 == 0){
        ans.first = n/2;
        ans.second = n/2;
    }
    else{
        if(color == 0){
            ans.first = (n+1)/2;
            ans.second = n-(n+1)/2;
        }
        else{
            ans.first = n-(n+1)/2;
            ans.second = (n+1)/2;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int current = 0;
        pair <int, int> a = {0, 0};
        pair <int, int> b = {0, 0};
        int current_color = 0;
        int step = 0;
        while(n){
            int res = min(n, current);
            n -= res;
            pair <int, int> aux = get_colors(current_color, res);
            if(step%4 == 0 or step%4 == 1){
                a.first += aux.first;
                a.second += aux.second;
            }
            else{
                b.first += aux.first;
                b.second += aux.second;
            }
            current_color += (current%2);
            current_color %=2;
            current++;
            step++;
        }
        cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    }
    return 0;
}