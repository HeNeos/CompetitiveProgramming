#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 0 day -> (, 0)
// 1 day -> (a, a-b)
// 2 day -> (2a-b, 2a-2b)
// 3 day -> (3a-2b, 3a-3b)
// k day -> (ka-(k-1)b, ka-kb)
// (n-1) day -> (, (n-1)a - (n-1)b)
// n day -> (,)
pair <ll, ll> calc_h(ll a, ll b, ll n){
    if(n == 1){
        return make_pair(1, a);
    }
    ll previous_day = 1LL*(n-1)*a - 1LL*(n-2)*b;
    pair <ll, ll> ans;
    ans.second = 1LL*n*a - 1LL*(n-1)*b;
    ans.first = previous_day + 1;
    return ans;
}

ll calc_days(ll h, ll a, ll b){
    ll ans = 1;
    ans = (h-b)/(a-b);
    if(ans*a - (ans-1)*b >= h) return max(ans, 1LL);
    ans++;
    if(ans*a - (ans-1)*b >= h) return max(ans, 1LL);
    return max(ans+1, 1LL);
}

int main(){
    int t; cin >> t;
    while(t--){
        int q; cin >> q;
        ll low_h = -1;
        ll high_h = -1;
        while(q--){
            int c; cin >> c;
            if(c == 1){
                ll a, b, n;
                cin >> a >> b >> n;
                pair <ll, ll> possible_h = calc_h(a, b, n);
                if(low_h == -1 and high_h == -1){
                    low_h = possible_h.first;
                    high_h = possible_h.second;
                    cout << 1 << " ";
                }
                else{
                    ll current_low = possible_h.first;
                    ll current_high = possible_h.second;
                    if(current_high < low_h or current_low > high_h){
                        cout << 0 << " ";
                    }
                    else{
                        cout << 1 << " ";
                        // cout << "HEIGHTS " << low_h << " " << high_h << '\n';
                        // cout << current_low << " " << current_high << endl;
                        // if(current_low >= low_h) low_h = current_low;
                        // if(current_high <= high_h) high_h = current_high;
                        if(current_low >= low_h and current_high <= high_h){
                            low_h = current_low;
                            high_h = current_high;
                            continue;
                        }
                        if(current_high <= high_h and current_low <= low_h){
                            high_h = current_high;
                            continue;
                        }
                        if(current_low >= low_h and current_high >= high_h){
                            low_h = current_low;
                            continue;
                        }
                    }
                }
            }
            else{
                ll a, b;
                cin >> a >> b;
                if(low_h == -1 and high_h == -1){
                    cout << -1 << " ";
                    continue;
                }
                // cout << "HEIGHTS " << low_h << " " << high_h << '\n';
                ll low_days = calc_days(low_h, a, b);
                ll high_days = calc_days(high_h, a, b);
                // cout << "DAYS: " << low_days << " " << high_days << endl;
                if(low_days != high_days) cout << -1 << " ";
                else cout << low_days << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}