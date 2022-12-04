#include <iostream>
#include <vector>
#include <string>

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

#define N 1001

int BIT[N+5][N+5];
bool m[N+5][N+5];

// Point Update - Range Query

void update(int x, int y, int v){
    for(int i=x+1; i<=N; i+=(i&-i)){
        for(int j=y+1; j<=N; j+=(j&-j))
            BIT[i][j] += v;
    }
}

int query(int x, int y){
    int ans = 0;
    for(int i=x; i; i-=(i&-i)){
        for(int j=y; j; j-=(j&-j))
            ans += BIT[i][j];
    }
    return ans;
}

void fill(){
    for(int i=0; i<N+5; i++){
        for(int j=0; j<N+5; j++) m[i][j] = false;
    }
    for(int i=0; i<N+5; i++){
        for(int j=0; j<N+5; j++) BIT[i][j] = 0;
    }
}

int main(){
    FIFO;
    int t; cin >> t;
    for(int c=1; c<=t; c++){
        fill();
        cout << "Case " << c << ":\n";
        int q; cin >> q;
        while(q--){
            int cas; cin >> cas;
            if(cas == 0){
                int x, y; cin >> x >> y;
                if(!m[x][y]){
                    m[x][y] = true;
                    update(x, y, 1);
                }
            }
            else{
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int ans = query(x2+1, y2+1);
                ans -= query(x1, y2+1);
                ans -= query(x2+1, y1);
                ans += query(x1, y1);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}