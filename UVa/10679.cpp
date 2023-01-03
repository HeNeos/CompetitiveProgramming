#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
typedef vector<int> vi;
struct SuffixAutomaton {
    int N = 1; int lastp = 0;
    vi link{-1}, len{0}, pos{-1};
    vector<map<char,int>> edges{1}; vector<bool> isClone{0};
    //link[i]   : the parent of i
    //len[i]    : the length of the longest string in the ith class
    //edges[i]  : the labeled edges from node i
    //pos[i]    : position of node i
    vector<vi> iLink; // inverse links
    vi endpos; //size of endpos class
    vi pp; vi DFSOrder; //DFS arrays
    vi terminals; //terminals nodes
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
        int x = getEdge(); link[cur] = x; pp.pb(x);
        return cur;
    }

    void addString(string s){
        for(int i=0; i<s.size(); i++) lastp = add(lastp, s[i]);    
    }

    bool solve(string s){
        int p = 0;
        for(int i=0; i<s.size(); i++){
            if(edges[p].find(s[i]) != edges[p].end()) p = edges[p][s[i]];
            else return false;
        }
        return true;
    }
};


int main() {
    int k; cin >> k;
    while(k--){
        string s; cin >> s;
        SuffixAutomaton S;
        S.addString(s);
        int q; cin >> q;
        string query;
        for(int i=0; i<q; i++){
            cin >> query;
            if(S.solve(query)) cout << 'y';
            else cout << 'n';
            cout << '\n';
        }
    }
    return 0;
}