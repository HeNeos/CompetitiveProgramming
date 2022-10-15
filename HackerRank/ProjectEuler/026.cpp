#include <bits/stdc++.h>
using namespace std;
#define N 10005

int cycle[N];
int maxi[N];
void fill(){
    int tmp, ctr_max = 0, total, i_max = 1;
    maxi[0] = 1; maxi[1] = 1;
    for(int i = 1; i<N; i++){
        tmp = i;
        while (tmp%2 == 0) tmp /= 2;
        while (tmp%5 == 0) tmp /= 5;
        if (tmp == 1){
            cycle[i] = 0;
            maxi[i] = maxi[i-1];
            continue;
        }

        int ctr = 1;
        for (total = 10;; ctr++) {
            if ((total %= tmp) == 1) break;
            total *= 10;
        }
        cycle[i] = ctr;
        if(cycle[maxi[i-1]] < ctr){
            maxi[i] = i;
        }
        else maxi[i] = maxi[i-1];
    }
}

int main(){
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << maxi[n-1] << '\n';
    }
    return 0;
}