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
};


string s1, s2;

pair <vector <int>, int> solve(SuffixAutomaton &S){
    int ans = 0; int p = 0; vector <int> out; int aux = 0;
    for(int i=0; i<s2.size(); i++){
        while(~p && !S.edges[p].count(s2[i])){
            p = S.link[p];
            if(~p) aux = S.len[p];
        }
        if(p == -1){p = 0; aux = 0; continue;}
        else{p = S.edges[p][s2[i]]; aux++;}
        if(aux >= ans){
            if(aux != ans) out.clear();
            out.pb(S.pos[p]); 
            ans = aux;
        }
    }
    return make_pair(out, ans);
}

void build(vector <int> &p, int &sz, vector <string> &a){
    for(int i=0; i<p.size(); i++){
        int start = p[i]-sz+1;
        a.pb(s1.substr(start,sz));
    }
}

void print(vector <string> &s){
    cout << s[0] << '\n';
    int last = 0;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[last]) continue;
        cout << s[i] << '\n';
        last = i;
    }
}

int main(){
    string ln;
    bool LaPtmrYaToyHarto = false;
    while(cin >> s1 >> s2){
        if(LaPtmrYaToyHarto) cout << '\n';
        SuffixAutomaton S;
        S.addString(s1);
        pair<vector <int>, int> ans = solve(S);
        int sz = ans.second; vector <int> p = ans.first;
        if(p.size() == 0) cout << "No common sequence.\n";
        else{
            vector <string> out;
            build(p, sz, out);
            sort(out.begin(), out.end());
            print(out);
        }
        LaPtmrYaToyHarto = true;
        getline(cin, ln);
    }
    return 0;
}