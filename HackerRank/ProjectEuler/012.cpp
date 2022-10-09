#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 600005
int lpf[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

vector <pair <int, int> > primesFactors(int n){
    vector <pair <int, int> > ans;
    while(n != 1){
        int d = lpf[n];
        int c = 0;
        while(n%d == 0){
            n /= d;
            c++;
        }
        ans.push_back(make_pair(d, c));
    }
    return ans;
}

vector <pair <int, int> > merge(vector <pair <int, int> > &a, vector <pair <int, int> > &b){
    vector <pair <int, int> > ans;
    int p1 = 0; int p2 = 0;
    for(; ;){
        if(p1 >= a.size() && p2 >= b.size()){
            break;
        }
        if(p1 >= a.size()){
            ans.push_back(b[p2]);
            p2++;
            continue;
        }
        if(p2 >= b.size()){
            ans.push_back(a[p1]);
            p1++;
            continue;
        }
        if(a[p1].first == b[p2].first){
            ans.push_back(make_pair(a[p1].first, a[p1].second + b[p2].second));
            p1++; p2++;
            continue;
        }
        if(a[p1].first < b[p2].first){
            ans.push_back(a[p1]);
            p1++;
            continue;
        }
        if(a[p1].first > b[p2].first){
            ans.push_back(b[p2]);
            p2++;
            continue;
        }
    }
    return ans;
}

int amountOfDivisors(vector <pair <int, int> > &p){
    int ans = 1;
    for(int i=0; i<p.size(); i++)
        ans *= (p[i].second+1);
    return ans;
}

int dp[N];

void fill(){
    for(int i=2; i<N-1; i++){
        if(i%2 == 0){
            vector <pair <int, int> > a = primesFactors(i/2);
            vector <pair <int, int> > b = primesFactors(i+1);
            vector <pair <int, int> > ans = merge(a, b);
            dp[i] = amountOfDivisors(ans);
        }
        else{
            vector <pair <int, int> > a = primesFactors(i);
            vector <pair <int, int> > b = primesFactors((i+1)/2);
            vector <pair <int, int> > ans = merge(a, b);
            dp[i] = amountOfDivisors(ans);
        }
    }
}

int main() {
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // x = N*(N+1)/2
        for(int i=2; i<N; i++){
            if(dp[i] > n){
                cout << 1LL*i*(i+1)/2 << '\n';
                break;
            }
        }
    }
    return 0;
}
