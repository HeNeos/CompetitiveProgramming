#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 5000005

int collatz[N];
int maximum[N];
void fill(){
    collatz[1] = 0;
    maximum[1] = 1;
    for(int i=2; i<N; i++){
        long long x = i;
        vector <long long> visited;
        while(x != 1){
            if(x < N && collatz[x] != 0){
                if(i != x) collatz[i] += collatz[x];
                break;
            }
            if(x&1) x = (x<<1)+x+1;
            else x >>=1;
            visited.push_back(x);
            collatz[i]++;
        }
        for(int j=0; j<visited.size(); j++){
            if(visited[j] >= N) continue;
            collatz[visited[j]] = collatz[i] - (j+1);
        }
        if(collatz[maximum[i-1]] <= collatz[i])
            maximum[i] = i;
        else
            maximum[i] = maximum[i-1];
    }
}

int main() {
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << maximum[n] << '\n';
    }
    return 0;
}
