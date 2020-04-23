#include <bits/stdc++.h>
using namespace std;
int prim[10000005];
long long fastexp(long long a, long long b){
  if(b==0) return 1;
  if(b==1) return a;
  if(b%2 == 0){
    long long aux = fastexp(a,b/2);
    return 1LL*aux*aux;
  }
  long long aux = fastexp(a,(b-1)/2);
  return 1LL*a*aux*aux;
}
void lpf(){
    for(int i=0; i<10000005; i++) prim[i] = 0;
    for(int i=2; i<10000005; i++){
        if(!prim[i]){
            for(int j=1; 1LL*j*i<10000005; j++){
                if(!prim[1LL*i*j]) prim[1LL*i*j] = i;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lpf();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n==1){
      cout << 1 << '\n';
      continue;
    }
    vector <pair <long long,long long> > div;
    int auxn = n;
    while(auxn>1){
      int fdiv = prim[auxn];
      div.push_back(make_pair(fdiv,0));
      while(prim[auxn]==fdiv){
        auxn = auxn/fdiv;
        div[div.size()-1].second++;
      }
    }
    long long answ = 1;
	for(int i=0; i<div.size(); i++){
		long long numm = div[i].first;
		long long expp = div[i].second;
		long long aux1 = fastexp(numm,2*expp);
		long long aux2 = fastexp(numm,2*expp-1);
		answ = 1LL*answ*(aux1-aux1/numm+((aux2+1)/(numm+1)));
	}
    cout << answ << '\n';
  }
  return 0;
}
