#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){
    int n, c; cin >> n >> c;
    int op[n]; int v[n];
    for(int i=0; i<n; i++)
        cin >> op[i] >> v[i];
    vector <int> ans(n);
    for(int i=0; i<30; i++){
        int b = ((c>>i) & 1);
        array<int,2> func = {0, 1};
        for(int j=0; j<n; j++){
            array<int,2> f;
            int x = ((v[j]>>i) & 1);
            if(op[j] == 1) f = {0&x, 1&x};
            else if(op[j] == 2) f = {0|x, 1|x};
            else if(op[j] == 3) f = {0^x, 1^x};
            func = {f[func[0]], f[func[1]]};
            b = func[b];
            ans[j] |= (b<<i);
        }
    }
    for(int i=0; i<n; i++) cout << ans[i] << '\n';
    return 0;
}