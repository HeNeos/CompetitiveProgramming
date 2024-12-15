#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
#define MAXN 10000000
using pii = pair<ll, ll>;

set <pair <ll, pii> > triplets;

#define N 800

void generateTriplets(){
  for(int n=1; n<=N; n++){
    for(int m=n+1; m<=N; m++){
      ll a = 1LL*(m+n)*(m-n);
      ll b = 2LL*m*n;
      ll c = 1LL*m*m + 1LL*n*n;
      ll g = __gcd(a, b);
      a /= g; b /= g; c /= g;
      triplets.insert(make_pair(c, make_pair(a, b)));
    }
  }
}

ll lcm(ll a, ll b){
  return 1LL*a*b / __gcd(a, b);
}

ll is_square(ll x){
  ll approx = sqrt(x);
  ll lo = max(approx*0, approx/2);
  ll hi = approx*2;
  while(lo < hi){
    ll me = lo + (hi-lo+1)/2;
    if(me*me <= x) lo = me;
    else hi = me-1;
  }
  if(lo*lo == x) return lo;
  else return -1;
}

ll solve(){
  ll ans = 0;
  vector <pair <ll, pii> > triangles;
  triangles.assign(triplets.begin(), triplets.end());
  sort(triangles.begin(), triangles.end());
  int sz = triangles.size();
  for(int i=0; i<88000; i++){
    ll r_1 = triangles[i].second.first;
    for(int j=i; j<88000; j++){
      ll r_2 = triangles[j].second.first;
      ll r = lcm(r_1, r_2);
      for(ll inradius=r;; inradius+=r){
        ll k_1 = inradius / r_1;
        ll k_2 = inradius / r_2;
        ll d_1 = triangles[i].first * k_1;
        ll d_2 = triangles[j].first * k_2;
        ll c = (k_1 * triangles[i].second.second + k_2 * triangles[j].second.second);
        if(3 * c > 2LL * MAXN) break;
        ll num = (c*k_1*triangles[i].second.second*k_2*triangles[j].second.second);
        ll den = (num/c - inradius*inradius);
        if(den <= 0) continue;
        if(num % den != 0) continue;
        ll p = num/den;
        if(2*p > MAXN) break;
        ll d_3 = (p-c)*(p-c) + inradius*inradius;
        d_3 = is_square(d_3);
        if(d_3 != -1){
          if(d_3 < d_2 or d_3 < d_1) continue;
          ans += d_1 + d_2 + d_3 + 2*p;
        }
      }
    }
  }
  return ans;
}

int main(){
  generateTriplets();
  unsigned long long ans = solve();
  cout << ans << '\n';
  return 0;
}
