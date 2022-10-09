#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll factorial[14];

void fill(){
    factorial[0] = 1;
    for(int i=1; i<14; i++)
        factorial[i] = factorial[i-1]*i;
}

int main() {
    fill();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string ans = "";
        vector <int> letters(13, 0);
        for(int i=0; i<13; i++) letters[i] = i;
        for(int i=0; i<13; i++){
            int left = 12-i;
            int block = (n + factorial[left] - 1)/factorial[left] - 1;
            //ans += ((block) + 'a');
            ans += ('a'+letters[block]);
            letters.erase(letters.begin()+block);
            n -= 1LL*block*factorial[left];
        }
        cout << ans << '\n';
    }
    return 0;
}
