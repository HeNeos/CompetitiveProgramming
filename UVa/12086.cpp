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
    for(int _=1;; _++){
        cin >> N;
        if(N == 0) break;
        if(_ != 1) cout << '\n';
        BIT.clear();
        BIT.resize(N+5, 0);
        vector <int> a(N);
        for(int i=0; i<N; i++) cin >> a[i];
        for(int i=0; i<N; i++) update(i, a[i]);
        string cas;
        bool firstM = true;
        for(;;){
            cin >> cas;
            if(cas == "END") break;
            if(cas == "M"){
                int l, r; cin >> l >> r;
                r--; l--;
                if(firstM){
                    cout << "Case " << _ << ":\n";
                    firstM = false;
                }
                if(l == 0) cout << query(r) << '\n';
                else cout << query(r) - query(l-1) << '\n';
            }
            else{
                int pos, value; cin >> pos >> value;
                update(pos-1, value - a[pos-1]);
                a[pos-1] = value;
            }
        }
    }
    return 0;
}