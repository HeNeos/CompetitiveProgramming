#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 5000005
typedef pair <int, int> pii;
typedef pair <int, pii> piii;

struct tern{
    int a; int b; int c;
};

vector <piii> terns;
set <piii> s;
void gen_terns(){
    for(int n=1; n<1500; n++){
        ll aux = 4LL*n*n;
        if(aux > N) break;
        for(int m=n+1; m<1500; m++){
            ll a = 1LL*m*m - 1LL*n*n;
            ll b = 2LL*m*n;
            ll c = 1LL*m*m + 1LL*n*n;
            ll p = a+b+c;
            if(p > N) break;
            ll g = __gcd(__gcd(a, b), c);
            a /= g; b /= g; c /= g;
            s.insert(make_pair(a, make_pair(b, c)));
        }
    }
    for(auto v: s) terns.push_back(v);
}

int cont[N];
int maxi[N];
void fill(){
    for(auto v: terns){
        int a = v.first;
        int b = v.second.first;
        int c = v.second.second;
        int p = a+b+c;
        for(int i=1; i*p<N; i++) cont[p*i]++;
    }
    for(int i=1; i<N; i++){
        if(cont[maxi[i-1]] >= cont[i]) maxi[i] = maxi[i-1];
        else maxi[i] = i;
    }
}

int main(){
    gen_terns();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << maxi[n] << '\n';
    }
    return 0;
}