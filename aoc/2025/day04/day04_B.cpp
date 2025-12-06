#include <bits/stdc++.h>
using namespace std;

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};

vector<string> grid;

vector<pair<int, int>> get_neighbors(int x, int y) {
  vector<pair<int, int>> positions;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int mov_x = dx[i];
      int mov_y = dy[j];
      if (mov_x == 0 and mov_y == 0)
        continue;
      if (x + mov_x < 0 or x + mov_x >= grid.size())
        continue;
      if (y + mov_y < 0 or y + mov_y >= grid[0].size())
        continue;
      positions.push_back(make_pair(x + mov_x, y + mov_y));
    }
  }
  return positions;
}

int main() {
  string s;
  int ans = 0;
  while (cin >> s) {
    grid.push_back(s);
  }
  for (;;) {
    int step_count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] != '@')
          continue;
        vector<pair<int, int>> positions = get_neighbors(i, j);
        int count = 0;
        for (auto position : positions) {
          if (grid[position.first][position.second] == '@')
            count++;
        }
        if (count < 4) {
          grid[i][j] = '.';
          // cout << grid[i][j] << " " << i << " " << j << endl;
          // for (auto position : positions) {
          //   cout << position.first << " " << position.second << endl;
          // }
          step_count++;
        }
      }
    }
    if (step_count == 0)
      break;
    ans += step_count;
  }
  cout << ans << '\n';
  return 0;
}
