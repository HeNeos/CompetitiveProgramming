#include <iostream>
#include <vector>
using namespace std;

#define INF (1<<30)
#define N 205
struct block{
    int x, y, z;
};

vector <block> stacks;
long long dp[N][N];

void clean(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) dp[i][j] = -1;
    }
    stacks.clear();
}

// string gen(int x, int y, int z){
//     return to_string(x)+"#"+to_string(y)+"#"+to_string(z);
// }

// int decode(string s){
// 	stringstream ss(s);
//     string aux;
//     char delim = '#';
//     int val = -1;
//     while(!ss.eof()){
//         getline(ss, aux, delim);
//         val = stoi(aux);
//     }
//     return val;
// }

void solve(long long acum, pair <int, int> base, vector <int> &took){
    if(dp[base.first][base.second] == acum) return;
    dp[base.first][base.second] = max(dp[base.first][base.second], acum);
    for(int i=0; i<stacks.size(); i++){
        block dimensions = stacks[i];
        if(took[i] >= 3) continue;
        if(dimensions.x < base.first && dimensions.y < base.second){
            took[i]++;
            solve(acum + dimensions.z,
                make_pair(dimensions.x, dimensions.y),
                took
            );
            took[i]--;
        }
        if(dimensions.y < base.first && dimensions.z < base.second){
            took[i]++;
            solve(acum + dimensions.x,
                make_pair(dimensions.y, dimensions.z),
                took
            );
            took[i]--;
        }
        if(dimensions.x < base.first && dimensions.z < base.second){
            took[i]++;
            solve(acum + dimensions.y,
                make_pair(dimensions.x, dimensions.z),
                took
            );
            took[i]--;
        }
    }
    // solve(acum, base);
}

int main(){
    int c = 0;
    while(true){
        c++;
        int n; cin >> n;
        if(n == 0) break;
        clean();
        stacks.resize(3*n);
        for(int i=0; i<n; i++){
            int x, y, z; cin >> x >> y >> z;
        }
        vector <int> took(n);
        solve(0, make_pair(N-1, N-1), took);
        long long ans = -INF;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        cout << "Case " << c << ": maximum height = ";
        cout << ans << '\n';
    }
    return 0;
}
// TODO