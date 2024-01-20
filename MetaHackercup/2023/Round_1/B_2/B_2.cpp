#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100
#define INF (1<<25)
map<int, vector<int> > dp[N];

vector <int> get_divisors(int n){
    vector <int> ans;
    for(int i=1; 1LL*i*i<=n; i++){
        if(n%i == 0){
            ans.push_back(i);
            if(i != n/i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

ll factors(int n){
    ll ans = 0;
    for(int i=2; 1LL*i*i<=n; i++){
        while(n%i == 0){
            ans += i;
            n /= i;
        }
    }
    if(n != 1) ans += n;
    return ans;
}

vector <int> solve(int s, int n, vector <int> d){
    vector <int> ans;
    if(s < 0) return ans;
    if(s == n){
        ans.push_back(s);
        return ans;
    }
    if(dp[s].find(n) != dp[s].end()) return dp[s][n];
    vector <int> new_div;
    for(auto v: d)
        if(n%v == 0) new_div.push_back(v);
    int c = INF;
    for(auto v: new_div){
        vector <int> temp = solve(s-v, n/v, new_div);
        if(temp.size() == 0) continue;
        if(1 + temp.size() <= c){
            c = 1+temp.size();
            ans = temp;
            ans.push_back(v);
        }
    }
    dp[s][n] = ans;
    return ans;
}

int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case #" << _ << ": ";
        int p; cin >> p;
        if(p == 41){
            cout << "1 41\n";
            continue;
        }
        vector <int> d = get_divisors(p);
        ll s = factors(p);
        if(s <= 41){
            for(int i=0; i<N; i++) dp[i].clear();
            int c = INF;
            vector <int> ans;
            for(auto v: d){
                vector <int> temp = solve(41-v, p/v, d);
                if(temp.size() == 0) continue;
                if(1 + temp.size() <= c){
                    c = 1+temp.size();
                    ans = temp;
                    ans.push_back(v);
                }
            }

            cout << c << " ";
            for(auto v: ans) cout << v << " ";
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}