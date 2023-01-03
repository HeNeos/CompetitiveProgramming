#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
    
    void getAllOccur(vi& oc, int v){
        if (!isClone[v]) oc.pb(pos[v]); // terminal position
        for(int i=0; i<iLink[v].size(); i++) getAllOccur(oc, iLink[v][i]);
    }
    vi allOccur(string s){ // get all occurrences of s in automaton
        int cur = 0;
        for(int i=0; i<s.size(); i++){
            if (!edges[cur].count(s[i])) return {};
            cur = edges[cur][s[i]];
        }
        vi ans; getAllOccur(ans,cur); 
        for(int i=0; i<ans.size(); i++) ans[i] += 1-s.size(); // convert end pos -> start pos
        sort(ans.begin(), ans.end()); return ans;
    }
};

SuffixAutomaton S;

int transform(int p, vector <pair <int, int> > &a){
    int lo = 0, hi = a.size()-1;
    while(lo < hi){
        int me = lo + (hi-lo)/2;
        if(a[me].first > p) hi = me;
        else lo = me+1;
    }
    return a[lo-1].second;
}

void solve(string &q, vector <pair <int, int> > &p){
    vector <int> aux = S.allOccur(q);
    if(aux.size() == 0){
        cout << -1;
        return;
    }
    vector <int> ans(aux.size());
    for(int i=0; i<aux.size(); i++) ans[i] = transform(aux[i], p);
    
    int last = ans[0];
    int c = 1;
    cout << last;
    for(int i=1; i<ans.size(); i++){
        if(c >= 10) return;
        if(ans[i] == last) continue;
        else{
            cout << " ";
            c++;
            last = ans[i];
            cout << last;
        }
    }
}

bool cmp(pair <string,int> a, pair <string, int> b){
    if(a.first.size() < b.first.size()) return true;
    if(a.first.size() > b.first.size()) return false;
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
    
}

int main() {
    FIFO;
    int n; cin >> n;
    vector <pair<string, int>> data(n);
    vector <pair<int, int> > positions(n+1);
    for(int i=0; i<n; i++){cin >> data[i].first; data[i].second = i+1;}
    sort(data.begin(), data.end(), cmp);
    string DATA = "";
    for(int i=0; i<n; i++){
        positions[i].first = DATA.size(); positions[i].second = data[i].second;
        DATA += data[i].first; DATA += "#";
    }
    positions[n].first = DATA.size(); positions[n].second = -1;
    
    S.addString(DATA); S.genILink();

    int q; cin >> q;
    while(q--){
        string querie; cin >> querie;
        solve(querie, positions);
        cout << '\n';
    }
    return 0;
}