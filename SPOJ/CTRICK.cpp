#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> BIT;

void update(int pos, int v){
    for(int i=pos+1; i<=N; i+=(i&-i))
        BIT[i] += v;
}

int query(int r){ // [0, r)
    int ans = 0;
    for(int i=r; i; i-=(i&-i))
        ans += BIT[i];
    return ans;
}

int query(int l, int r){ // [l, r)
    return query(r) - query(l);
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> N;
        BIT.clear();
        BIT.resize(N+5);
        int current_pos = 0;
        vector <int> ans(N);
        for(int i=0; i<N; i++){
            int total_free = N - query(N);
            int current_free = current_pos - query(current_pos);
            int to_find = (current_free + (i+1))%total_free;
            int lo = 0;
            int hi = N-1;
            while(lo < hi){
                int me = lo + (hi-lo+1)/2;
                if(me - query(me) <= to_find) lo = me;
                else hi = me-1;
            }
            current_pos = lo;
            ans[current_pos] = i+1;
            // free(new_pos) = (free(current_pos) + (i+1)) % free(N)
            update(current_pos, 1);
        }
        for(int i=0; i<N; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;

}