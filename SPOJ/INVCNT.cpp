#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> BIT;
int N;

// Point Update - Range Query

void update(int pos, int v){
    for(++pos; pos<=N; pos += (pos&-pos))
        BIT[pos] += v;
}

int query(int r){
    int ans = 0;
    for(++r; r>0; r -= (r&-r))
        ans += BIT[r];
    return ans;
}

void transform(vector <int> &a){
    vector <pair<int, int> > aux(a.size());
    for(int i=0; i<a.size(); i++){
        aux[i].first = a[i];
        aux[i].second = i;
    }
    sort(aux.begin(), aux.end());
    for(int i=0; i<a.size(); i++)
        a[aux[i].second] = i;
}

long long solve(vector <int> &a){
    long long ans = 0;
    for(int i=a.size()-1; i>=0; i--){
        ans += query(a[i]);
        update(a[i], 1);
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        BIT.clear();
        cin >> N;
        BIT.resize(N+5, 0);
        vector <int> a(N);
        for(int i=0; i<N; i++) cin >> a[i];
        transform(a);
        cout << solve(a) << '\n';
    }
    return 0;
}