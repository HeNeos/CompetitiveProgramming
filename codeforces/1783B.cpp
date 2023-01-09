#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n][n];
        int prev = 1;
        int value = n*n-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[j][i] = prev;
                prev = prev + value;
                if(value > 0) value = 1-value;
                else value = -1-value;
            }
            int aux[n];
            if(i%2 == 1){
                for(int j=0; j<n; j++){
                    aux[n-j-1] = arr[j][i];
                }
                for(int j=0; j<n; j++){
                    arr[j][i] = aux[j];
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cout << arr[i][j] << " ";
            cout << '\n';
        }
    }
    return 0;
}