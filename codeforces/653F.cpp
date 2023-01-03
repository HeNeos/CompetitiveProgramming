#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define K 21
typedef vector<int> vi;
struct SuffixAutomaton {
    int N = 1; int lastp = 0;
    vi link{-1}, len{0}, pos{-1};
    vector<map<char,int>> edges{1}; vector<bool> isClone{0};
    //link[i]   : the parent of i
    //len[i]    : the length of the longest string in the ith class
    //edges[i]  : the labeled edges from node i
    //pos[i]    : position of node i
    int add(int p, char c){
        auto getEdge = [&]() {
            if (p == -1) return 0;
            int q = edges[p][c]; if (len[p]+1 == len[q]) return q;
            int clone = N++; link.pb(link[q]); link[q] = clone;
            len.pb(len[p]+1); edges.pb(edges[q]), pos.pb(pos[q]), isClone.pb(1);
            for (; ~p && edges[p][c] == q; p = link[p]) edges[p][c] = clone;
            return clone;
        };
        //if(edges[p].count(c)) return getEdge();// <- need if adding > 1 string
        int cur = N++; // make new state
        link.emplace_back(), len.pb(len[p]+1), edges.emplace_back(), pos.pb(pos[p]+1), isClone.pb(0);
        for(; ~p && !edges[p].count(c); p = link[p]) edges[p][c] = cur;
        int x = getEdge(); link[cur] = x;
        return cur;
    }

    void addString(string s){
        for(int i=0; i<s.size(); i++) lastp = add(lastp, s[i]);    
    }
};
SuffixAutomaton S;
string s;

vector <vector <int>> sp;
void build(){
    sp.resize(S.N, vector <int>(K, -1));
    vi open;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') open.push_back(i);
        else{
            if(!open.empty()){
                int p = open.back(); open.pop_back();
                sp[i][0] = p;
                for(int j=1; j<K && sp[i][j-1] > 0; j++){
                    sp[i][j] = sp[sp[i][j-1]-1][j-1];
                }
            }
        }
    }
}

ll solve(int p, int l){
    ll ans = 0;
    for(int i=K-1; i>=0 && p > 0; i--){
        if(sp[p][i] != -1 && p-sp[p][i]+1 <= l){
            ans += 1<<i;
            l -= p-sp[p][i]+1;
            p = sp[p][i]-1;
        }
    }
    return ans;
}

int main(){
    int sz; cin >> sz;
    cin >> s;
    S.addString(s);
    build();
    ll ans = 0;
    for(int i=1; i<S.N; i++)
        ans += solve(S.pos[i], S.len[i]) - solve(S.pos[i], S.len[S.link[i]]);
    cout << ans << '\n';
    return 0;
}