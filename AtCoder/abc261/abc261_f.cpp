#include <iostream>
#include <vector>
#include <string>

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int N;

vector <long long> BIT;

// Point Update - Range Query

void update(int pos, int v){
    for(int i=pos+1; i<=N; i+=(i&-i))
        BIT[i] += v;
}

long long query(int r){ // [0, r)
    long long ans = 0;
    for(int i=r; i; i-=(i&-i))
        ans += BIT[i];
    return ans;
}

long long query(int l, int r){ // [l, r)
    return query(r) - query(l);
}

int main(){
    FIFO;
    cin >> N;
    BIT.resize(N+5);
    int C[N]; int X[N];
    vector <int> a[N+1];
    for(int i=0; i<N; i++) cin >> C[i];
    for(int i=0; i<N; i++){
        cin >> X[i];
        a[0].push_back(X[i]-1);
        a[C[i]].push_back(X[i]-1);
    }
    long long ans = 0;
    for(int i=0; i<=N; i++){
        int sz = a[i].size();
        for(int j=0; j<sz; j++){
            if(i == 0) ans += query(a[i][j] + 1, N);
            else ans -= query(a[i][j] + 1, N);
            update(a[i][j], 1);
        }
        for(int j=0; j<sz; j++) update(a[i][j], -1);
    }
    cout << ans << '\n';
    return 0;
}