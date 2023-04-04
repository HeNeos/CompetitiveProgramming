#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a[4];
        for(int i=0; i<4; i++) cin >> a[i];
        if(a[0] == 0){
            cout << 1 << '\n';
            continue;
        }
        int a_mood = a[0];
        int b_mood = a[0];
        int ans = a[0];
        int x = min(a[1], a[2]);
        ans += 2*x;
        if(a[1] > x){
            int d = min(b_mood+1, a[1]-x);
            ans += d;
            b_mood -= d;
        }
        if(a[2] > x){
            int d = min(a_mood+1, a[2]-x);
            ans += d;
            a_mood -= d;
        }
        if(a_mood < 0 or b_mood < 0){
            cout << ans << '\n';
            continue;
        }
        ans += min(min(a_mood, b_mood) + 1, a[3]);
        cout << ans << '\n';
    }
    return 0;
}