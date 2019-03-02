#include <bits/stdc++.h>
using namespace std;
int lib[10000];
int main(){
    int n;
    int m;
    while (cin >> n){
        for (int i = 0; i < n; ++i) cin >> lib[i];    
        sort(lib, lib + n);
        cin >> m;
        int a = 0;
        int b = n - 1;
        int ba;
        int bb;
        while (a < b){
            if (lib[a] + lib[b] < m) a++;
            else{
            	if (lib[a] + lib[b] == m){
                	ba = a;
                	bb = b;
                	a++; b--;
            	}
            else b--;
        	}
        }
        cout << "Peter should buy books whose prices are " << lib[ba] << " and " << lib[bb] << ".\n\n";
    }
    return 0;
}
