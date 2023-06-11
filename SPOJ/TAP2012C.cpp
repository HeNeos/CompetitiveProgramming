#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define mods 1000000009
#define modhash1 1000000009
#define modhash2 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
ll mulmod(ll a, ll b, ll p){
    ll x = 0, y = a%p;
    while(b>0){
        if(b%2==1) x = (x+y)%p;
        y = (1LL*y*2)%p;
        b = b/2;
    }
    return x%p;
}
ll fastexp(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x);
        y = y>>1;
        x = (1LL*x*x);
    }
    return ans;
}
long long solve(vector <int> n, vector <int> dig, int pos, bool f){
    ll ans = 0;
    if(pos > n.size()){
        return ans;
    }
    for(int i=0; i<dig.size(); i++){
        if(f) ans += fastexp(dig.size(),n.size()-pos);
        else{
            if(dig[i] > n[pos-1]) break;
            if(dig[i] == n[pos-1]){
                if(pos == n.size()) ans++;
                ans += solve(n,dig,pos+1,false);
            }
            else{
                if(pos == n.size()) ans++;
                ans += solve(n,dig,pos+1,true);
            }
        }
    }
    return ans;
}

int main(){
    while(true){
        ll a, b, c;
        string s;
        bool zero = false;
        cin >> a >> b >> c >> s;
        a--;
        
        if(s[0] == '*') break;
        vector <int> digit;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'S') digit.pb(i);
        }
        
        if(s[0] == 'S') zero = true;

        vector <int> ac, bc;
        if(a == 0) ac.pb(0);    
        while(a>=1){
            ac.pb(a%c);
            a = a/c;
        }
        
        while(b>=1){
            bc.pb(b%c);
            b = b/c;
        }

        reverse(ac.begin(), ac.end());
        reverse(bc.begin(), bc.end());
        
        ll cant1 = solve(ac,digit,1,false);
        ll cant2 = solve(bc,digit,1,false);
        if(!zero){
            for(int i=ac.size()-1; i>=0; i--)
                cant1 += 1LL*fastexp(digit.size(),i);
            
            for(int i=bc.size()-1; i>=0; i--)
                cant2 += 1LL*fastexp(digit.size(),i);
        }
        cout << cant2-cant1 << '\n';
    }
    return 0;
}
