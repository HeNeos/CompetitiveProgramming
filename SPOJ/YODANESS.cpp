#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector <int> BIT;
int N;

// Point Update - Range Query

void update(int pos, int v){
    for(++pos; pos<=N; pos += (pos&-pos))
        BIT[pos] += v;
}

int query(int r){
    int ans = 0;
    for(++r; r>0; r -= (r&-r))
        ans += BIT[r];
    return ans;
}

long long solve(vector <int> &a){
    long long ans = 0;
    for(int i=a.size()-1; i>=0; i--){
        ans += query(a[i]);
        update(a[i], 1);
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        BIT.clear();
        cin >> N;
        BIT.resize(N+5, 0);
        map <string, int> m;
        for(int i=0; i<N; i++){
            string s; cin >> s;
            m[s] = i;
        }
        vector <int> a(N);
        for(int i=0; i<N; i++){
            string s; cin >> s;
            a[m[s]] = i;
        }
        cout << solve(a) << '\n';
    }
    return 0;
}