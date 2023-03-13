#include <bits/stdc++.h>
using namespace std;
vector <pair <int,int> > table;
int b[210];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		table.push_back(make_pair(a,0));
	}
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		table[i].second = a;
	}
	sort(table.begin(), table.end());
	reverse(table.begin(), table.end());
	int ind = 0;
	int ind2 = 0;
	for(int i=0; i<n; i++) b[table[i].second]++;
	int sum = 0;
	int ans = 100000000;
	while(ind < n){
		while(ind2 < n && table[ind].first == table[ind2].first){
			b[table[ind2].second]--;
			ind2++;
		}
		int cur = sum;
		int p = (n-ind2)-(ind2-ind)+1;
		int c = 0;
		while(p > 0){
			int x = min(p, b[c]);
			cur = cur+c*x;
			p = p-x;
			c++;
		}
		ans = min(ans, cur);
		while(ind < ind2){
			sum = sum+table[ind].second;
			ind++;
		}
	}
	cout << ans;
	return 0;
}
