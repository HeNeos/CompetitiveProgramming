#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
typedef vector<int> vi;
struct SuffixAutomaton {
    int N = 1; int lastp = 0;
    vi link{-1}, len{0}, pos{-1};
    vector<map<char,int>> edges{1}; vector<bool> isClone{0};
    //link[i]   : corresponds to the longest suffix that is in a different class
    //len[i]    : the length of the longest string in the ith class
    //edges[i]  : the labeled edges from node i
    //pos[i]    : the first ending position of such a string
    vector<vi> iLink; // inverse links
    vi endpos; vi pp; vi DfsOrder; vector <bool> vis;
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
        pp.pb(cur);
        return cur;
    }

    void addString(string s){
        for(int i=0; i<s.size(); i++) lastp = add(lastp, s[i]);    
    }

    void genILink(){ // inverse links
        iLink.resize(N); 
        for(int v=1; v<N; v++) iLink[link[v]].pb(v);
    }

    void Dfs(int x){
        if(vis[x]) return;
        for(auto v:edges[x]) Dfs(v.second);
        vis[x] = true;
        DfsOrder.pb(x);
    }

    void BuildEndpos(){
        endpos.resize(N);
        vis.resize(N);
        for(int i=0; i<pp.size(); i++) endpos[pp[i]] = 1;
        Dfs(0);
        for(int i=0; i<DfsOrder.size(); i++){
            int p = link[DfsOrder[i]];
            if(p == -1) continue;
            endpos[p] += endpos[DfsOrder[i]];
        }
    }
};


string s;

void dfs(SuffixAutomaton &S, int &ans, int x = 0){
    if(!S.vis[x]) return;
    if(S.endpos[x] >= 2) ans = max(ans, S.len[x]);
    for(auto v:S.edges[x]) dfs(S, ans, v.second);
    S.vis[x] = false;
}

int main() {
    int t; cin >> t;
    while(t--){
        cin >> s;
        SuffixAutomaton S;
        S.addString(s); S.genILink(); S.BuildEndpos();
        int ans = 0;
        dfs(S, ans);
        cout << ans << '\n';
    }
}