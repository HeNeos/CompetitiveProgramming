#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 270;
char grid[MAXN][MAXN];

bool check(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first, y1 = p1.second;
  int x2 = p2.first, y2 = p2.second;

  int xmin = min(x1, x2), xmax = max(x1, x2);
  int ymin = min(y1, y2), ymax = max(y1, y2);

  for (int y = ymin; y <= ymax; y++) {
    for (int x = xmin; x <= xmax; x++) {
      if (grid[y][x] != 'R' && grid[y][x] != 'G') {
        return false;
      }
    }
  }

  return true;
}

vector<string> split(const string &str, char delimiter = ' ') {
  vector<string> words;
  string word;

  for (char ch : str) {
    if (ch == delimiter) {
      if (!word.empty()) {
        words.push_back(word);
        word.clear();
      }
    } else
      word += ch;
  }
  if (!word.empty())
    words.push_back(word);
  return words;
}

vector<int> compress(vector<int> &coords, unordered_map<int, int> &mp) {
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());

  for (int i = 0; i < coords.size(); i++)
    mp[coords[i]] = i;

  return coords;
}

bool point_in_polygon(float x, float y, const vector<pair<int, int>> &poly) {
  bool inside = false;
  int n = poly.size();
  for (int i = 0, j = n - 1; i < n; j = i++) {
    float xi = poly[i].first, yi = poly[i].second;
    float xj = poly[j].first, yj = poly[j].second;

    bool intersect = ((yi > y) != (yj > y)) &&
                     (x < (xj - xi) * (y - yi) / (yj - yi + 0.0) + xi);

    if (intersect)
      inside = !inside;
  }
  return inside;
}

int main() {
  string s;
  ll ans = 0;
  vector<pair<int, int>> points;
  while (cin >> s) {
    vector<string> line = split(s, ',');
    int x = stoi(line[0]);
    int y = stoi(line[1]);
    points.push_back({x, y});
  }

  int n = points.size();

  vector<int> xs, ys;
  xs.reserve(n);
  ys.reserve(n);

  for (auto &p : points) {
    xs.push_back(p.first);
    ys.push_back(p.second);
  }

  unordered_map<int, int> xmap, ymap;
  compress(xs, xmap);
  compress(ys, ymap);

  int W = xs.size();
  int H = ys.size();

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++)
      grid[i][j] = '.';
  }

  vector<pair<int, int>> poly(n);
  for (int i = 0; i < n; i++) {
    poly[i].first = xmap[points[i].first];
    poly[i].second = ymap[points[i].second];
  }

  for (int i = 0; i < n; i++) {
    int j = i + 1;
    if (j >= poly.size()) {
      j = 0;
    }
    int p1_x = poly[i].first;
    int p1_y = poly[i].second;
    int p2_x = poly[j].first;
    int p2_y = poly[j].second;

    grid[p1_y][p1_x] = 'R';
    grid[p2_y][p2_x] = 'R';

    if (p1_x == p2_x) {
      int m = min(p1_y, p2_y);
      int M = max(p1_y, p2_y);
      for (int k = m + 1; k < M; k++)
        grid[k][p1_x] = 'G';
    }
    if (p1_y == p2_y) {
      int m = min(p1_x, p2_x);
      int M = max(p1_x, p2_x);
      for (int k = m + 1; k < M; k++)
        grid[p1_y][k] = 'G';
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (grid[y][x] == 'R' || grid[y][x] == 'G')
        continue;
      if (point_in_polygon(x + 0.5, y + 0.5, poly))
        grid[y][x] = 'G';
    }
  }

  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      ll area = 1LL * (abs(points[i].first - points[j].first) + 1) *
                (abs(points[i].second - points[j].second) + 1);
      if (area > ans) {
        if (check(make_pair(xmap[points[i].first], ymap[points[i].second]),
                  make_pair(xmap[points[j].first], ymap[points[j].second]))) {
          ans = area;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
