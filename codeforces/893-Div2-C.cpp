#include <bits/stdc++.h>
using namespace std;
vector <int> friends[100005];
bool characters[100005];
vector <pair <int,int> > cost;
int auxcost[100005];
long long answ = 0;
int bfs(int s){
	queue <int> q;
	q.push(s);
	characters[s] = true;
	int val = auxcost[s];
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int u:friends[x]){
			if(characters[u] == false){
				characters[u] = true;
				q.push(u);
			}
		}
	}
	return val;
}
int main(){
	int n, m;
	cin >> n >> m;
	auxcost[0] = 0;
	for(int i=0; i<100005; i++) characters[i] = false;
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		auxcost[i] = a;
		cost.push_back(make_pair(a,i));
	}
	sort(cost.begin(), cost.end());
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for(int i=0;i<n; i++){
		if(characters[cost[i].second] == false){
			answ = answ + bfs(cost[i].second);
		}
	}
	cout << answ;
	return 0;
}	
 	  			  		 	 	 	 		     	 		
