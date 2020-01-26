#include <bits/stdc++.h>
using namespace std;
vector <int> g[2005];
bool visited[2005];
vector <int> bosses;
int cont = 0;
int dfs(int s, int p){
	cont = max(cont,p);
	visited[s] = true;
	for(int u:g[s]){
		if(!visited[u]){
			dfs(u,p+1);
		}
	}
	return cont;
}
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		if(a!=-1) g[a].push_back(i);
		else bosses.push_back(i);
	}
	int answ = -1;
	for(int i=0; i<bosses.size(); i++){
		for(int i=0; i<2005; i++) visited[i] = false;
		cont = 0;
		answ = max(answ,dfs(bosses[i],0));
	}
	cout << answ+1;
	return 0;
}
