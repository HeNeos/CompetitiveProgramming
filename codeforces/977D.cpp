#include <bits/stdc++.h>
using namespace std;
bool ss(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b){
    if(a.second.first > b.second.first) return false;
    if(a.second.first < b.second.first) return true;
    if(a.second.second > b.second.second) return true;
    else return false;
}
int main(){
    int n;
    cin >> n;
    vector <pair <int, pair <int,int> > > factors; 
    long long values[n];
    for(int i=0; i<n; i++){
        cin >> values[i];
        long long aux = values[i];
        int cont2 = 0;
        int cont3 = 0;
        while(aux%2 == 0 or aux%3 == 0){
            if(aux%2 == 0){
                cont2++;
                aux = aux/2;
            }
            if(aux%3 == 0){
                cont3++;
                aux = aux/3;
            }
        }
        factors.push_back(make_pair(i,make_pair(cont2,cont3)));
    }
    sort(factors.begin(), factors.end(),ss);
    for(int i=0; i<n; i++) cout << values[factors[i].first] << " ";
    return 0;
}
