#include <iostream>
#include <vector>
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

vector <long long> BIT;
int N;
void update(int pos, int v){
    for(++pos; pos<=N; pos+=(pos&-pos))
        BIT[pos] += v;
}

void range_update(int l, int r, int v) {
    update(l, v);
    update(r+1, -v);
}

long long query(int pos) {
    long long ans = 0;
    for (++pos; pos>0; pos-=(pos&-pos))
        ans += BIT[pos];
    return ans;
}


int main(){
	FIFO;
    int m, c;
    cin >> N >> m >> c;
    BIT.resize(N+5);
    for(int i=0; i<m; i++){
        char q; cin >> q;
        if(q == 'Q'){
            int p; cin >> p;
            p--;
            cout << 1LL*c + query(p) << '\n';
        }
        else{
            int u, v, k;
            cin >> u >> v >> k;
            u--; v--;
            range_update(u, v, k);
        }
    }
    return 0;
}