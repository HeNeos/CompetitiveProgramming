#include <iostream>
#include <vector>
#include <string>

#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int N;

vector <vector <long long> > BIT;
vector <vector <long long> > m;

// Point Update - Range Query

void update(int x, int y, int v){
    for(int i=x+1; i<=N; i+=(i&-i)){
        for(int j=y+1; j<=N; j+=(j&-j))
            BIT[i][j] += v;
    }
}

long long query(int x, int y){
    long long ans = 0;
    for(int i=x; i; i-=(i&-i)){
        for(int j=y; j; j-=(j&-j))
            ans += BIT[i][j];
    }
    return ans;
}

void fill(){
    BIT.clear();
    m.clear();
    BIT.resize(N+5);
    m.resize(N+5);
    for(int i=0; i<N+5; i++){
        BIT[i].resize(N+5);
        m[i].resize(N+5);
    }
}

int main(){
    FIFO;
    int t; cin >> t;
    while(t--){
        cin >> N;
        fill();
        while(true){
            string cas; cin >> cas;
            if(cas == "SET"){
                int x, y, v; cin >> x >> y >> v;
                update(x, y, v-m[x][y]);
                m[x][y] = v;
            }
            else if(cas == "SUM"){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                long long ans = query(x2+1, y2+1);
                ans -= query(x1, y2+1);
                ans -= query(x2+1, y1);
                ans += query(x1, y1);
                cout << ans << '\n';
            }
            else if(cas == "END") 
                break;
            cout << '\n';
        }
    }
    return 0;
}