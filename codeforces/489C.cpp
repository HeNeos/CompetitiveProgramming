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
ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = (1LL*x*x)%p;
    }
    return ans%p;
}
ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = mulmod(ans,x,p);
        y = y>>1;
        x = mulmod(x,x,p);
    }
    return ans%p;
}
ll invmod(ll x, ll p){
    return fastexp(x,p-2,p)%p;
}
bool check_composite(ll n, ll a, ll d, int s){
    ll x = fastexp(a,d,n);
    if(x == 1 || x == n-1) return false;
    for(int r=1; r<s; r++){
        x = (1LL*x*x)%n;
        if(x == n-1) return false;
    }
    return true;
}
bool isPrime(ll p){
    if(p<=1) return false;
    int r = 0;
    ll d = p-1;
    while(!(d&1)){
        d >>= 1;
        r++;
    }
    for(int i=0; i<12; i++){
        int value = TestMillerRabin[i];
        if(p == value) return true;
        if(check_composite(p,value,d,r)) return false;
    }
    return true;
}
vector <pll> pothash;
vector <pll> invpothash;
vector <pll> prefhash(string &p){
    int pi=31;
    vector <pll> pref;
    pothash.clear();
    invpothash.clear();
    pothash.pb(mp(1,1));
    for(int i=1; i<p.size(); i++){
        ll auxi1 = (1LL*pothash[i-1].first*pi)%modhash1;
        ll auxi2 = (1LL*pothash[i-1].second*pi)%modhash2;
        pothash.pb(mp(auxi1,auxi2));
    }
    invpothash.pb(mp(0,0));
    invpothash.pb(mp(1,1));
    for(int i=2; i<p.size(); i++){
        ll auxi1 = (1LL*invpothash[modhash1%i].first*(modhash1-modhash1/i))%modhash1;
        ll auxi2 = (1LL*invpothash[modhash2%i].second*(modhash2-modhash2/i))%modhash2;
        invpothash.pb(mp(auxi1,auxi2));
    }
    for(int i=0; i<p.size(); i++){
        if(i>0){
            ll auxi1 = (pref[i-1].first+((p[i]-'a'+1)*pothash[i].first)%modhash1)%modhash1;
            ll auxi2 = (pref[i-1].second+((p[i]-'a'+1)*pothash[i].second)%modhash2)%modhash2;
            pref.pb(mp(auxi1,auxi2));
        }
        else pref.pb(mp(p[i]-'a'+1,p[i]-'a'+1));
    }
    return pref;
}
pll hashsubs(string &p, int i, int j, vector <pll> &pp){
    int pi=31;
    int sz = j-i+1;
    if(sz == 0) return mp(-1,-1);
    if(i == 0) return pp[i+sz-1];
    ll fp1 = (pp[i+sz-1].first-pp[i-1].first+modhash1)%modhash1;
    ll sp1 = invpothash[pothash[i].first].first;
    ll fp2 = (pp[i+sz-1].second-pp[i-1].second+modhash2)%modhash2;
    ll sp2 = invpothash[pothash[i].second].second;
    return mp((1LL*fp1*sp1)%modhash1,(1LL*fp2*sp2)%modhash2);
}
int main(){
    int m, s;
    cin >> m >> s;
    if(m == 1 and s<=9){
        cout << s << " " << s << '\n';
        return 0;
    }
    string maxs = "";
    string mins = "";
    int cant9 = s/9;
    for(int i=0; i<cant9; i++) maxs += '9';
    if(maxs.size() != m) maxs += (s%9+'0');
    //for(int i=0; i<maxs.size(); i++) mins += maxs[maxs.size()-i-1];
    for(int i=cant9+1; i<m; i++) maxs += '0';
    
    int auxs = s;
    mins += (max(s-9*(m-1),1)+'0');
    auxs -= max(s-9*(m-1),1);
    for(int i=1; i<m; i++){
        mins += (max(auxs-9*(m-1-i),0)+'0');
        //cout << max(s-9*(m-1-i),0) << '\n';
        auxs -= max(auxs-9*(m-1-i),0);
    }
    /*string auxmin = "1";
    for(int i=cant9+2; i<m; i++) auxmin += "0";
    auxmin = auxmin + mins;*/
    bool noansw = false;
    int sum = 0;
    for(int i=0; i<mins.size(); i++) sum += (mins[i]-'0');
    if(sum != s) noansw = true;
    sum = 0;
    for(int i=0; i<maxs.size(); i++) sum += (maxs[i]-'0');
    if(mins.size() != m or maxs.size() != m) noansw = true;
    //cout << sum << '\n';
    if(sum != s) noansw = true;
    if(mins[0] == '0' or maxs[0] == '0') noansw = true;
    if(noansw) cout << -1 << " " << -1 << '\n';
    else cout << mins << " " << maxs << '\n';    
    return 0;
}
