#include <bits/stdc++.h>
using namespace std;
#define M 100
using pii = pair<int, int>;

int get_area(int a, int b, int c, int d){
  return (a*b + b*c + c*d + a*d);
}

int find_points(pii p0, pii p1){
  int dx = abs(p1.first - p0.first);
  int dy = abs(p1.second - p0.second);
  int g = __gcd(dx, dy);
    // p0.first + k*dx = p1.first
  return g+1;
}

int solve(int a, int b, int c, int d){
  int area = get_area(a, b, c, d);
  pii A = {a, 0};
  pii B = {0, b};
  pii C = {-c, 0};
  pii D = {0, -d};
  int exterior_points = find_points(A, B) + find_points(B, C) + find_points(C, D) + find_points(D, A);
  exterior_points -= 4;
  return (area + 2 - exterior_points);
}

bool is_square(int x){
  int sq = sqrt(x*1.0);
  return sq*sq == x;
}

int main(){
  int ans = 0;
  for(int a=1; a<=M; a++){
    for(int b=1; b<=M; b++){
      for(int c=1; c<=M; c++){
        for(int d=1; d<=M; d++){
          int inside_points = solve(a, b, c, d);
          if(is_square(inside_points/2)) ans++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
