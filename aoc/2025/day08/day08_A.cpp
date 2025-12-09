#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Position = pair<int, array<int, 3>>;
using Neighbor = pair<double, Position>;

struct KDNode {
  Position p;
  KDNode *left = nullptr, *right = nullptr;
  int axis;
};

struct PairD {
  int idA, idB;
  double d;
};

double dist3D(const Position &a, const Position &b) {
  long long dx = a.second[0] - b.second[0];
  long long dy = a.second[1] - b.second[1];
  long long dz = a.second[2] - b.second[2];
  return sqrt(dx * dx + dy * dy + dz * dz);
}

KDNode *buildKD(vector<Position> &pts, int depth = 0) {
  if (pts.empty())
    return nullptr;

  int axis = depth % 3;
  int mid = pts.size() / 2;

  nth_element(pts.begin(), pts.begin() + mid, pts.end(),
              [axis](const Position &a, const Position &b) {
                return a.second[axis] < b.second[axis];
              });

  KDNode *node = new KDNode();
  node->p = pts[mid];
  node->axis = axis;

  vector<Position> left(pts.begin(), pts.begin() + mid);
  vector<Position> right(pts.begin() + mid + 1, pts.end());

  node->left = buildKD(left, depth + 1);
  node->right = buildKD(right, depth + 1);

  return node;
}

void nearest(KDNode *node, const Position &target, Position &bestP,
             double &bestD) {
  if (!node)
    return;

  double d = dist3D(target, node->p);
  if (d > 0 && d < bestD) {
    bestD = d;
    bestP = node->p;
  }

  int axis = node->axis;
  long long diff = target.second[axis] - node->p.second[axis];

  KDNode *first = diff < 0 ? node->left : node->right;
  KDNode *second = diff < 0 ? node->right : node->left;

  nearest(first, target, bestP, bestD);

  if (fabs(diff) < bestD) {
    nearest(second, target, bestP, bestD);
  }
}

void k_nearest(KDNode *node, const Position &target,
               priority_queue<Neighbor> &pq, int k) {
  if (!node)
    return;

  double d = dist3D(target, node->p);

  if (d > 0) {
    if ((int)pq.size() < k) {
      pq.emplace(d, node->p);
    } else if (d < pq.top().first) {
      pq.pop();
      pq.emplace(d, node->p);
    }
  }

  int axis = node->axis;
  long long diff = target.second[axis] - node->p.second[axis];

  KDNode *first = diff < 0 ? node->left : node->right;
  KDNode *second = diff < 0 ? node->right : node->left;

  k_nearest(first, target, pq, k);

  if ((int)pq.size() < k || fabs(diff) < pq.top().first) {
    k_nearest(second, target, pq, k);
  }
}

struct DSU {
  unordered_map<int, int> parent;
  unordered_map<int, int> rank;

  int find(int x) {
    if (!parent.count(x)) {
      parent[x] = x;
      rank[x] = 0;
    }
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb)
      return;

    if (rank[ra] < rank[rb])
      swap(ra, rb);
    parent[rb] = ra;
    if (rank[ra] == rank[rb])
      rank[ra]++;
  }
};

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

int main() {
  string s;
  vector<Position> positions;
  int id = 0;
  while (cin >> s) {
    vector<string> line = split(s, ',');
    int x = stoi(line[0]);
    int y = stoi(line[1]);
    int z = stoi(line[2]);
    positions.push_back({id, {x, y, z}});
    id++;
  }

  vector<Position> copy = positions;
  KDNode *root = buildKD(copy);

  vector<PairD> allPairs;

  for (auto &p : positions) {
    priority_queue<Neighbor> pq;
    k_nearest(root, p, pq, 10);
    while (!pq.empty()) {
      Neighbor element = pq.top();
      Position neighbor = element.second;
      if (p.first < neighbor.first)
        allPairs.push_back({p.first, neighbor.first, element.first});
      pq.pop();
    }
  }

  sort(allPairs.begin(), allPairs.end(),
       [](auto &a, auto &b) { return a.d < b.d; });

  vector<pair<int, int>> solution;
  for (auto &r : allPairs) {
    int first_position = r.idA;
    int second_position = r.idB;
    solution.push_back({first_position, second_position});
    if (solution.size() >= 1000)
      break;
  }

  DSU dsu;

  for (auto &p : solution) {
    dsu.unite(p.first, p.second);
  }

  unordered_map<int, vector<int>> groups;
  for (auto &p : solution) {
    int r1 = dsu.find(p.first);
    int r2 = dsu.find(p.second);

    groups[r1].push_back(p.first);
    groups[r1].push_back(p.second);

    if (r2 != r1) {
      groups[r2].push_back(p.second);
      groups[r2].push_back(p.first);
    }
  }

  for (auto &g : groups) {
    auto &vec = g.second;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
  }

  vector<int> groups_size;
  for (auto &g : groups) {
    auto &vec = g.second;
    groups_size.push_back(vec.size());
  }
  sort(groups_size.rbegin(), groups_size.rend());
  int sz = groups_size.size();
  ll ans = 0;
  if (sz >= 1)
    ans = groups_size[0];
  if (sz >= 2)
    ans *= groups_size[1];
  if (sz >= 3)
    ans *= groups_size[2];

  cout << ans << '\n';
  return 0;
}
