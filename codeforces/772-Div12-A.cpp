#include <bits/stdc++.h>
using namespace std;
vector <int> aaa;
vector <int> bbb;
vector <pair <int, int> > devi;
double test(double tim, int na, int power, vector <int> cc, vector <int> rr){
	double timaux = 0;
	for(int i=0; i<cc.size(); i++){
		double cost = 1.0*tim*cc[i];
		double rest = 1.0*rr[i];
		if(rest<cost){
			timaux += 1.0*(cost-rest)/power;
		}
	}
	return timaux;
}
int main(){
	int n;
	int p;
	cin >> n >> p;
	while(n--){
		int a;
		int b;
		cin >> a >> b;
		aaa.push_back(a);
		bbb.push_back(b);
		devi.push_back(make_pair(a,b));
	}
	double lo = 0;
	double hi = 1e14;
	for(int i=1; i<=100; i++){
		double me = 1.0*(hi+lo)/2;
		if(test(me,n,p,aaa,bbb) <= me) lo = me;
		else hi = me;
	}
	if(lo> 1e11) cout << -1;
	else printf("%.10lF", lo);
	return 0;
}
