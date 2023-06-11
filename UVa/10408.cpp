#include<bits/stdc++.h>
using namespace std;
vector <pair <int, int> > vii;
bool cmp(pair<int, int> a,pair<int , int> b){
    if(a.first*b.second>b.first*a.second) return(false);
    else return(true);
}
int main(){
    long long N;
    long long k;
    while(cin>>N,cin>>k){
        vii.clear();
        vii.push_back(make_pair(1,1));
        long long cont=1;
        for(int i=1; i<=N-1; i++){
            for(int j=i+1; j<=N; j++){
                if(j%i==0 && i!=1) continue;
                if(__gcd(j,i)!=1) continue;
                vii.push_back(make_pair(i,j));
                //cout<<vii[cont].first<<"/"<<vii[cont].second<<endl;
                cont++;
            }
        }
        sort(begin(vii),end(vii),cmp);
        //for(int i=0; i<cont; i++){
        //    cout<<vii[i].first<<"/"<<vii[i].second<<endl;
        //}
        cout<<vii[k-1].first<<"/"<<vii[k-1].second<<endl;
    }
}
