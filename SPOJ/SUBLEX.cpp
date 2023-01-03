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

    void genILink(){ // inverse links
        iLink.resize(N); 
        for(int v=1; v<N; v++) iLink[link[v]].pb(v);
    } 
    
    void getAllOccur(vi& oc, int v) {
        if (!isClone[v]) oc.pb(pos[v]); // terminal position
        for(int i=0; i<iLink[v].size(); i++) getAllOccur(oc, iLink[v][i]);
    }
    vi allOccur(string s) { // get all occurrences of s in automaton
        int cur = 0;
        for(int i=0; i<s.size(); i++){
            if (!edges[cur].count(s[i])) return {};
            cur = edges[cur][s[i]];
        }
        vi ans; getAllOccur(ans,cur); 
        for(int i=0; i<ans.size(); i++) ans[i] += 1-s.size(); // convert end pos -> start pos
        sort(ans.begin(), ans.end()); return ans;
    }

    vector <ll> distinct;
    ll getDistinct(int x){ //# of distinct strings starting at state x
        if (distinct[x]) return distinct[x];
        distinct[x] = 1; 
        for(auto v:edges[x]) distinct[x] += getDistinct(v.second);
        return distinct[x];
    }
    ll numDistinct(){ //# distinct substrings including empty
        distinct.resize(N); return getDistinct(0);
    }

    ll countSubStrings(){
        ll ans = 1; 
        for(int i=1; i<N; i++) ans += len[i]-len[link[i]];
        return ans;
    }
};

SuffixAutomaton S;
string s;

void solve(ll k, int source, string &ans){
    if(k <= 0) return;
    ll taked = 0; int node = 0; char c = '#';
    for(auto v:S.edges[source]){
        if(taked + S.distinct[v.second] >= k){
            node = v.second;
            c = v.first;
            taked++;
            break;
        }
        else
            taked += S.distinct[v.second];
    }
    ans += c;
    solve(k-taked, node, ans);
    return;
}

int main() {
    cin >> s;
    S.addString(s); S.genILink(); S.numDistinct();
    int q; cin >> q;
    while(q--){
        ll k; cin >> k;
        string ans = "";
        solve(k, 0, ans);
        cout << ans << '\n';
    }
}