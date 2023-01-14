#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 300005

int lpf[N];
vector <int> pr;
int pi[N];
void sieve(){
	for(int i=2; i<N; i++){
		if(!lpf[i]){
			lpf[i] = i;
            pr.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i){
				if(lpf[j] == 0) lpf[j] = i;
			}
		}
	}
    for(int i=0; i<pr.size(); i++)
        pi[pr[i]] = i;
}

vector <int> factors(int x){
    vector <int> ans;
    while(x > 1){
        int d = lpf[x];
        ans.push_back(pi[d]); // store the index of the prime | 2 -> 0, 3 -> 1
        while(x%d == 0) x/=d;
    }
    return ans;
}

vector <int> g[N];
bool vis[N];
int previous[N];
int dis[N];

void bfs(int u){
    queue <int> q;
    q.push(u);
    previous[u] = u;
    dis[u] = 0;
    vis[u] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<g[node].size(); i++){
            if(vis[g[node][i]] == false){
                q.push(g[node][i]);
                vis[g[node][i]] = true;
                previous[g[node][i]] = node;
                dis[g[node][i]] = dis[node] + 1;
            }
        }
    }
}


int main(){
    sieve();
    int n; cin >> n;
    int a[n];
    vector <vector <int> > ff(pr.size());
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        vector <int> f = factors(a[i]);
        for(int j=0; j<f.size(); j++){
            ff[f[j]].push_back(i); // store the index of spider
        }
    }
    int s, t; cin >> s >> t;
    s--; t--;
    for(int i=0; i<ff.size(); i++){
        for(int j=0; j<ff[i].size(); j++){
            for(int k=j+1; k<ff[i].size(); k++){
                g[ff[i][j]].push_back(ff[i][k]);
                g[ff[i][k]].push_back(ff[i][j]);
            }
        }
    }
    bfs(s);
    if(vis[t]){
        cout << dis[t]+1 << '\n';
        vector <int> ans;
        int node = t;
        ans.push_back(node);
        while(true){
            if(node == s) break;
            ans.push_back(previous[node]);
            node = previous[node];
        }
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i]+1 << " ";
        }
        cout << '\n';
    }
    else{
        cout << "-1\n";
    }


    return 0;
}