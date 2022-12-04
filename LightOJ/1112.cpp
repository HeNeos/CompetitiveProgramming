#include <iostream>
#include <vector>
#include <string>

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

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

int main(){
    FIFO;
    int t; cin >> t;
    for(int c=1; c<=t; c++){
        int q;
        cin >> N >> q;
        BIT.clear();
        BIT.resize(N+5, 0);
        vector <int> a(N);
        for(int i=0; i<N; i++) cin >> a[i];
        for(int i=0; i<N; i++) update(i, a[i]);
        cout << "Case " << c << ":\n";
        for(int _=0; _<q; _++){
            int cas; cin >> cas;
            if(cas == 1){
                int pos; cin >> pos;
                int ans = query(pos) - query(pos-1);
                cout << ans << '\n';
                update(pos, -ans);
            }
            else if(cas == 2){
                int pos, value; cin >> pos >> value;
                update(pos, value);
            }
            else if(cas == 3){
                int l, r; cin >> l >> r;
                cout << query(r) - query(l-1) << '\n';
            }
        }
    }
    return 0;
}