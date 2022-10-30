#include <iostream>
#include <queue>
using namespace std;

#define N  8
struct position{
    int r, c;
};

int dist[N][N];

void fill_dist(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) dist[i][j] = -1;
    }
}

vector <position> get_positions(position u){
    vector <position> positions;
    int r_moves[4] = {-2, -1, 1, 2};
    int c_moves[4] = {-2, -1, 1, 2};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(abs(r_moves[i]) + abs(c_moves[j]) != 3) continue;
            position valid;
            valid.r = u.r + r_moves[i];
            valid.c = u.c + c_moves[j];
            if(valid.r < 0 or valid.r >= 8) continue;
            if(valid.c < 0 or valid.c >= 8) continue;
            positions.push_back(valid);
        }
    }
    return positions;
}

void bfs(position s){
    queue <position> q;
    dist[s.r][s.c] = 0;
    q.push(s);
    while(!q.empty()){
        position current = q.front();
        q.pop();
        for(auto next_position : get_positions(current)){
            if(dist[next_position.r][next_position.c] != -1) continue;
            dist[next_position.r][next_position.c] = dist[current.r][current.c] + 1;
            q.push(next_position);
        }
    }
}


int main(){
    int t; cin >> t;
    while(t--){
        fill_dist();
        int rb, cb, re, ce;
        char RB; cin >> RB;
        cin >> cb; cb--;
        char RE; cin >> RE;
        cin >> ce; ce--;
        rb = (int)(RB - 'a'); re = (int)(RE - 'a');
        position start; start.r = rb; start.c = cb;
        bfs(start);
        cout << dist[re][ce] << '\n';
    }
    return 0;
}