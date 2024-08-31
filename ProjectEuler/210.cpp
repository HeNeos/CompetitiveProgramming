#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int MAX_R = 1000000000;

pii get_boundaries(int x) { return make_pair(MAX_R - abs(x), -MAX_R + abs(x)); }

ll count_solutions(int x) {
  ll det = 1LL * MAX_R * MAX_R / 16 + 1LL * MAX_R * x - 4LL * x * x;
  if (det < 0)
    return 0;
  double sq = sqrt((double)det);
  double upper_bound = ((double)MAX_R) / 8 + sq / 2;
  double lower_bound = ((double)MAX_R) / 8 - sq / 2;
  ll upper = floor(upper_bound);
  ll lower = ceil(lower_bound);
  if (upper_bound == upper)
    upper--;
  if (lower_bound == lower)
    lower++;
  return upper - lower + 1;
}

ll solve_left() {
  ll ans = 1;
  for (int left_line = -MAX_R + 1; left_line < 0; left_line++) {
    int aligned_y = left_line;
    pii boundaries = get_boundaries(left_line);
    int down = max(aligned_y - boundaries.second, 0);
    int middle = min(-left_line, boundaries.first) -
                 max(aligned_y, boundaries.second) + 1;
    if (boundaries.second <= aligned_y)
      middle--;
    if (boundaries.first >= -left_line)
      middle--;
    middle = max(middle, 0);
    int up = boundaries.first - min((MAX_R / 2 - left_line), boundaries.first);
    up = max(up, 0);
    ans += down + middle + up;
    ans += count_solutions(left_line);
  }
  ans += MAX_R + MAX_R / 4 - 1 + MAX_R - MAX_R / 2;
  cout << "left " << ans << '\n';
  return ans;
}

ll solve_right() {
  ll ans = 1;
  for (int right_line = MAX_R / 4 + 1; right_line < MAX_R; right_line++) {
    int aligned_y = right_line;
    pii boundaries = get_boundaries(right_line);
    int down = max(-aligned_y - boundaries.second, 0);
    int middle = min(aligned_y, boundaries.first) -
                 max((MAX_R / 2 - right_line), boundaries.second) + 1;
    if (boundaries.first >= aligned_y)
      middle--;
    if (boundaries.second <= MAX_R / 2 - right_line)
      middle--;
    middle = max(middle, 0);
    int up = max(boundaries.first - aligned_y, 0);
    ans += down + middle + up;
    ans += count_solutions(right_line);
  }
  ans += (MAX_R - MAX_R / 4 - MAX_R / 4) + (MAX_R / 4 - 1) +
         (MAX_R - MAX_R / 4 - MAX_R / 4);
  cout << "right " << ans << '\n';
  return ans;
}

ll solve_middle() {
  ll ans = 0;
  for (int middle_line = 1; middle_line < MAX_R / 4; middle_line++) {
    int aligned_y = middle_line;
    pii boundaries = get_boundaries(middle_line);
    int down = max(-middle_line - boundaries.second, 0);
    int middle = count_solutions(middle_line);
    int up = max(boundaries.first - (MAX_R / 2 - middle_line), 0);
    ans += down + middle + up - 1;
  }
  cout << "middle " << ans << '\n';
  return ans;
}

int main() {
  int r;
  cin >> r;
  if (r != -1)
    MAX_R = r;
  unsigned long long ans = solve_left();
  ans += solve_right();
  ans += solve_middle();
  cout << ans << '\n';
  return 0;
}