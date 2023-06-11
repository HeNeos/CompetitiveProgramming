#include <bits/stdc++.h>
using namespace std;
int prim = 1000000007;
long long fastexp(long long a, long long b, long long p){
    if(b==0) return 1;
    if(b==1) return a%p;
    if(b%2==0){
        long long aux = fastexp(a,b/2,p)%p;
        return (1LL*aux*aux)%p;
    }
    long long aux = fastexp(a,(b-1)/2,p)%p;
    return ((1LL*aux*aux)%p*a)%p;
}
map<long long, long long> chonion;
int main(){
    long long n, x;
    cin >> n >> x;
    vector <long long> exp;
    long long sum = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        sum += a;
        exp.push_back(a);
    }
    sort(exp.begin(), exp.end());
    for(int i=0; i<n; i++){
        chonion[-exp[i]]++;
    }
    for(auto i:chonion){
        if(i.first < 0 and i.second >= x){
            int what = i.second/x;
            chonion[i.first] = i.second%x;
            chonion[i.first+1] = chonion[i.first+1]+what;
        }
    }
    exp.clear();
    vector <pair<int,int> > expcant;
    for(auto i:chonion){
        if(i.second > 0) expcant.push_back(make_pair(-i.first,i.second));
    }
    long long auxsum = sum;
    sum = 0;
    for(int i=0; i<expcant.size(); i++) sum = sum + expcant[i].first;
    long long times = expcant[0].second;    
    long long expoo = expcant[0].first;
    long long answ = fastexp(x,sum-expoo,prim)%prim;
    answ = (1LL*answ*fastexp(x,auxsum-sum,prim)%prim)%prim;
    cout << answ;
    return 0;
}
