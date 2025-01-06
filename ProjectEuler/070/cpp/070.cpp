#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define N 10000005

ll phi[N];
void cphi(){
    phi[1] = 1;
    for(ll i=2; i<N; i++){
        if(!phi[i]){
            phi[i] = i-1;
            for(ll j=2LL*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

bool isPermutation(ll x, ll y){
    vector <int> d1(10);
    while(x > 0){
        d1[x%10]++;
        x /= 10;
    }
    while(y > 0){
        d1[y%10]--;
        y /= 10;
    }
    for(int i=0; i<10; i++){
        if(d1[i] != 0) return false;
    }
    return true;
}

bool cmp(pair <int, int> a, pair<int, int> b){
    return 1LL*a.second*b.first > 1LL*a.first*b.second;
}

int main(){
    cphi();
    vector <pair< int, int> > ans;
    int n; cin >> n;
    for(int i=2; i<n; i++){
        if(isPermutation(i, phi[i])){
            //cout << i << " " << phi[i] << endl;
            ans.push_back(make_pair(i, phi[i]));
        }
    }
    sort(ans.begin(), ans.end(), cmp);

    cout << ans[0].first;
}
