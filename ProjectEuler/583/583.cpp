#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 10000000
using pii = pair<ll, ll>;

set <pair <ll, pii> > triplets;
map <int, vector<int> > catetes;

#define N 2300

void generateTriplets(){
  for(int n=1; n<=N; n++){
    for(int m=n+1; m<=N; m++){
      ll a = 1LL*(m+n)*(m-n);
      ll b = 2LL*m*n;
      ll c = 1LL*m*m + 1LL*n*n;
      ll g = __gcd(a, b);
      a /= g; b /= g; c /= g;
      if(a > b) swap(a, b);
      triplets.insert(make_pair(c, make_pair(a, b)));
    }
  }
}

ll integer_sqrt(ll x){
  double sq = sqrt((double) x);
  ll lo = sq/2;
  ll hi = 2*sq;
  while(lo < hi){
    ll me = lo + (hi-lo+1)/2;
    if(me*me <= x) lo = me;
    else hi = me-1;
  }
  return lo;
}

vector <int> get_divisors(int x){
  vector <int> d;
  for(int i=1; 1LL*i*i<=x; i++){
    if(x%i == 0){
      d.push_back(i);
      if(i != x/i) d.push_back(x/i);
    }
  }
  sort(d.begin(), d.end());
  return d;
}

ll find_triangle(int width, int height){
  ll ans = 0;
  int new_base = width/2;
  vector <int> d = get_divisors(new_base);
  for(auto divisor: d){
    vector <int> triangles = catetes[divisor];
    if(triangles.size() == 0) continue;
    int k = new_base/divisor;
    for(auto triangle: triangles){
      ll perimeter = width + 2*height;
      ll a = 1LL * divisor * k;
      ll b = 1LL * triangle * k;
      if(b > height) continue;
      if(perimeter + 2*a > MAXN or perimeter + 2*b > MAXN) continue;
      int c = integer_sqrt(a*a + b*b);
      if(perimeter + 2*c <= MAXN){
        int new_height = height + b;
        ll x = 1LL*a*a + 1LL*new_height*new_height;
        ll sq = integer_sqrt(x);
        if(sq*sq == x){
          perimeter += 2*c;
          ans += perimeter;
          cout << width << " " << height << " " << b << " " << c << "\n";
        }
      }
    }
  }
  return ans;
}

ll solve(){
  generateTriplets();
  vector <pair <ll, pii> > triangles;
  triangles.assign(triplets.begin(), triplets.end());
  sort(triangles.begin(), triangles.end());
  for(auto triangle: triangles){
    int a = triangle.second.first;
    int b = triangle.second.second;
    catetes[a].push_back(b);
    catetes[b].push_back(a);
  }
  ll ans = 0;
  for(int i=0; i<triangles.size(); i++){
    int a = triangles[i].second.first;
    int b = triangles[i].second.second;
    int c = triangles[i].first;
    if(a%2 == 0){
      for(int mult=1;; mult++){
        int new_a = a*mult;
        int new_b = b*mult;
        if(2*new_a + 2*new_b >= MAXN) break;
        ans += find_triangle(new_a, new_b);
        if(mult%2 == 0) ans += find_triangle(new_b, new_a);
      }
    }
    else{
      if(b%2 == 0){
        for(int mult=1;; mult++){
          int new_a = a*mult;
          int new_b = b*mult;
          if(2*new_b + 2*new_a >= MAXN) break;
          ans += find_triangle(new_b, new_a);
          if(mult%2 == 0) ans += find_triangle(new_a, new_b);
        }
      }
      else{
        for(int mult=2; mult; mult+=2){
          int new_a = a*mult;
          int new_b = b*mult;
          if(2*new_a + 2*new_b >= MAXN) break;
          ans += find_triangle(new_b, new_a);
          ans += find_triangle(new_a, new_b);
        }
      }
    }
  }
  return ans;
}

int main(){
  cout << solve() << '\n';
  return 0;
}
