#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define N 464160
#define MAXN 100000000000000000LL
#define MAX_CACHE 10000000

unordered_map<ll, int> m;
ll cache[MAX_CACHE];
ll perfect_cubes[N];

void fill_cubes() {
  for (int i = 0; i < N; i++) {
    perfect_cubes[i] = 1LL * i * i * i;
  }
}

ll cbrt(ll x) {
  uint64_t b, y, one = 1, bits = 3 * 21;
  int s;
  for (s = bits - 3; s >= 0; s -= 3) {
    if ((x >> s) == 0)
      continue;
    x -= one << s;
    y = 1;
    for (s = s - 3; s >= 0; s -= 3) {
      y += y;
      b = 1 + 3 * y * (y + 1);
      if ((x >> s) >= b) {
        x -= b << s;
        y += 1;
      }
    }
    return y;
  }
}

ll find_nearest_cube(ll x) {
  int ans = cbrt(x);
  return perfect_cubes[ans];
}

int solve(ll x) {
  if (x == 0)
    return 0;
  if (x < MAX_CACHE && cache[x])
    return cache[x];
  if (m.find(x) != m.end())
    return m[x];
  ll nearest_cube = find_nearest_cube(x);
  int ans = 1 + solve(x - nearest_cube);
  if (x < MAX_CACHE)
    cache[x] = ans;
  else {
    if (m.size() < 5000000 and ans > 5)
      m[x] = ans;
  }
  return ans;
}

pair<ll, ll> level_sum[N + 5];

int main() {
  fill_cubes();
  ll previous_sum = 28;
  ll current_sum = 28;
  ll ans = 0;
  ll current_number = 8;
  int position_last_cube = 1;
  int current_value = -1;
  ll length_current_interval = -1;
  ll last_print = 10;
  ll total_skipped = 0;
  ll total_count = 0;
  for (;;) {
    if (current_number >= MAXN)
      break;
    if (current_number == perfect_cubes[position_last_cube + 1]) {
      previous_sum = current_sum;
      ans += previous_sum;
      current_value = 1;
      length_current_interval = perfect_cubes[position_last_cube + 1] -
                                perfect_cubes[position_last_cube];
      level_sum[position_last_cube - 1] =
          make_pair(previous_sum, length_current_interval);
      current_number += length_current_interval - 1;
      position_last_cube++;
      total_skipped += length_current_interval;
      if (current_number > last_print) {
        cout << current_number << " " << log10(1.0 * current_number) << '\n';
        last_print *= 1.225;
      }
    } else {
      current_value = solve(current_number);
      current_sum += current_value;
      total_count++;
    }
    current_number++;
  }
  ll previous_number = current_number - length_current_interval + 1;
  if (previous_number == perfect_cubes[position_last_cube] + 1) {
    previous_number--;
    ll length_difference = MAXN - previous_number;
    for (int i = position_last_cube - 2; i >= 0; i--) {
      if (level_sum[i].second <= length_difference) {
        previous_number += level_sum[i].second;
        ans += level_sum[i].first;
        break;
      }
    }
    for (ll x = previous_number; x < MAXN; x++) {
      ans += solve(x);
      total_count++;
    }

  } else {
    vector<int> v;
    ans += current_sum + v.size();
  }
  cout << ans << '\n';
  return 0;
}
