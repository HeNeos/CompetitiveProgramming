#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define pb push_back
typedef vector<int> vi;
using ll = long long;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
struct SuffixAutomaton {
    int N = 1; int lastp = 0;
    vi link{-1}, len{0}, pos{-1};
    vector<map<char,int>> edges{1}; vector<bool> isClone{0};
    //link[i]   : the parent of i
    //len[i]    : the length of the longest string in the ith class
    //edges[i]  : the labeled edges from node i
    //pos[i]    : position of node i
    vector <bool> terminal; //terminals nodes
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

    void findTerminals(){
        terminal.resize(N);
        int p = lastp;
        while(p){
            terminal[p] = 1;
            p = link[p];
        }
    }
    vector <ll> substrings;
    ll getDistinct(int x){ //# of distinct strings starting at state x, x = 0: all substrings
        if (substrings[x] != -1) return substrings[x];
        ll ans = terminal[x]; 
        for(auto v:edges[x]) ans += getDistinct(v.second);
        substrings[x] = ans;
        return ans;
    }
};

SuffixAutomaton S;
string s;
int sz;

int solve(string &q){
    q += q;
    int r = 0; int cur = 0; int ans = 0;
    set <int> vis;
    for(int l=0; l<sz; l++){
        int len = r-l;
        if(cur){
            if(S.len[S.link[cur]] >= len) cur = S.link[cur];
        }
        while(r-l < sz && S.edges[cur].count(q[r])){
            cur = S.edges[cur][q[r]];
            r++;
        }
        if(r-l < sz) continue;
        if(!vis.count(cur))
            ans += S.substrings[cur];
        vis.insert(cur);
    }
    return ans;
}

int main() {
    FIFO;
    cin >> s;
    S.addString(s); S.findTerminals(); 
    S.substrings.resize(S.N, -1); S.getDistinct(0);
    int t; cin >> t;
    while(t--){
        string q; cin >> q; sz = q.size();
        cout << solve(q) << '\n';
    }
    return 0;
}