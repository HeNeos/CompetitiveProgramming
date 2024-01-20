#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define mp make_pair
#define pb push_back

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int findLongestCommonPrefix(string& str1, string& str2) {
    int minLength = min(str1.size(), str2.size());
    int ans = 0;
    for (int i = 0; i < minLength; i++){
        if (str1[i] == str2[i]) ans++;
        else break;
    }
    return ans;
}

int findLongestCommonSuffix(string& str1, string& str2) {
    int str1_len = str1.size();
    int str2_len = str2.size();
    int minLength = min(str1_len, str2_len);
    int ans = 0;

    for (int i = 1; i <= minLength; i++){
        if (str1[str1_len - i] == str2[str2_len - i]) ans++;
        else break;
    }
    return ans;
}

#define N 4005

struct state{
    int len, link;
    bool terminal; //Is the state terminal ?
    map<char, int> next;
};

struct SuffixAutomaton{
    state st[N << 1];
    int cnt, last;
    vector <vi> iLink;
    vi occur;
    void init(){
        //root node is at index 0.
        cnt = 0, last = 0;
        st[0].len = 0; st[0].link = -1; st[0].terminal = 0;
        cnt++;
    }
    
    void sa_extend(char c){
        int cur = cnt++;
        st[cur].len = st[last].len + 1;
        st[cur].terminal = 0;
        int p = last;
        while(p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if(p == -1) st[cur].link = 0;
        else{
            int q = st[p].next[c];
            if(st[q].len == st[p].len + 1) st[cur].link = q;
            else{
                int clone = cnt++;
                st[clone].terminal = 0; st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link; st[clone].next = st[q].next;
                st[cur].link = st[q].link = clone;
                while(p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
            }
        }
        last = cur;
    }
    
    void find_terminals(){
        int p = last;
        while(p) {
            st[p].terminal = 1;
            p = st[p].link;
        }
    }
    
    void addString(string s){
        init();
        for(int i=0; i<s.size(); i++) sa_extend(s[i]);
        find_terminals();
    }

    void genILink(){ // inverse links
        iLink.resize(last); 
        for(int v=1; v<last; v++) iLink[st[v].link].pb(v);
    }

    int getOccur(int i){
        if(occur[i] != -1) return occur[i];
        int ans = st[i].terminal;
        for(auto v:st[i].next)
            ans += getOccur(v.second);
        occur[i] = ans;
        return ans;
    }

    int matchString(string &q){
        int cur = 0; occur.resize(N, -1);
        for(int i=0; i<q.size(); i++){
            if (!st[cur].next.count(q[i])) return 0;
            cur = st[cur].next[q[i]];
        }
        return getOccur(cur);
    }

    void printSA(){
        for(int i = 0; i < cnt; i++) {
            cout << "i: " << i << '\n';
            cout << "Terminal: " << st[i].terminal << '\n';
            cout << "Transitions:\n"; 
            for(auto p : st[i].next)
                cout << p.first << " -> " << p.second << '\n';
            
            cout << "Suf Link: " << st[i].link << '\n';
            cout << '\n';
        }
    }
};


int main(){
    FIFO;
    int n; cin >> n;
    SuffixAutomaton S[n];
    for(int i=0; i<n; i++){
        int m; cin >> m;
        string x = " ";
        for(int j=0; j<m; j++){
            string temp; cin >> temp;
            x += temp;
            x += " ";
        }
        S[i].addString(x);
    }
    int p; cin >> p;
    for(int i=0; i<p; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int sz1 = s1.size();
        int sz2 = s2.size();
        int pref = findLongestCommonPrefix(s1, s2);
        int suf = findLongestCommonSuffix(s1, s2);
        bool rejected = false;
        for(int pr=pref; pr>=0; pr--){
            for(int su=suf; su>=0; su--){
                if(pr + su >= min(sz1, sz2)) continue;
                string new_s1 = " " + s1.substr(pr, sz1-pr-su) + " ";
                string new_s2 = " " + s2.substr(pr, sz2-pr-su) + " ";
                for(int j=0; j<n; j++){
                    if(S[j].matchString(new_s1) > 0 && S[j].matchString(new_s2) > 0){
                        rejected = true;
                        break;
                    }
                }
                if(rejected) break;
            }
            if(rejected) break;
        }
        if(rejected) cout << "REJECT";
        else cout << "OK";
        cout << '\n';
    }
    return 0;
}