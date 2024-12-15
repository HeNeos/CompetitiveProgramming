#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FIFO                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

const ll INF = 1LL << 60;

class SegmentTree {
private:
  struct Node {
    ll sum = -INF;
    ll prefix = -INF;
    ll sufix = -INF;
    ll subArray = -INF;
  };

public:
  vector<Node> nodes;
  vector<int> array;
  int size;

  SegmentTree(vector<int> _array) {
    size = _array.size();
    array = _array;
    nodes.clear();
    nodes.resize(4 * size);
  }

  void build(int nodeId, int left, int right) {
    if (right - left < 1) {
      nodes[nodeId] = {array[left], array[left], array[left], array[left]};
      return;
    }
    int mid = (left + right) / 2;
    int leftNodeId = 2 * nodeId;
    int rightNodeId = 2 * nodeId + 1;
    build(leftNodeId, left, mid);
    build(rightNodeId, mid + 1, right);

    nodes[nodeId] = {
        nodes[leftNodeId].sum + nodes[rightNodeId].sum,
        max(nodes[leftNodeId].prefix,
            nodes[leftNodeId].sum + nodes[rightNodeId].prefix),
        max(nodes[leftNodeId].sufix + nodes[rightNodeId].sum,
            nodes[rightNodeId].sufix),
        max(nodes[leftNodeId].sufix + nodes[rightNodeId].prefix,
            max(nodes[leftNodeId].subArray, nodes[rightNodeId].subArray))};
  }

  Node query(int nodeId, int leftRange, int rightRange, int leftPosition,
             int rightPosition) {
    int midRange = (leftRange + rightRange) / 2;

    int leftNodeId = 2 * nodeId;
    int rightNodeId = 2 * nodeId + 1;

    if (leftRange > rightRange or leftRange > rightPosition or
        rightRange < leftPosition) {
      Node invalidPosition = {0, -INF, -INF, -INF};
      return invalidPosition;
    }

    if (leftRange >= leftPosition and rightRange <= rightPosition)
      return nodes[nodeId];

    Node leftQuery =
        query(leftNodeId, leftRange, midRange, leftPosition, rightPosition);
    Node rightQuery = query(rightNodeId, midRange + 1, rightRange, leftPosition,
                            rightPosition);

    Node queryNode = {leftQuery.sum + rightQuery.sum,
                      max(leftQuery.prefix, leftQuery.sum + rightQuery.prefix),
                      max(leftQuery.sufix + rightQuery.sum, rightQuery.sufix),
                      max(leftQuery.sufix + rightQuery.prefix,
                          max(leftQuery.subArray, rightQuery.subArray))};

    return queryNode;
  }

  void clean() { nodes.clear(); }
};

int main() {
  FIFO;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  SegmentTree ST = SegmentTree(a);
  ST.build(1, 0, n - 1);

  int m;
  cin >> m;

  while (m--) {
    int left, right;
    cin >> left >> right;
    left--;
    right--;
    auto ans = ST.query(1, 0, n - 1, left, right);
    cout << ans.subArray << '\n';
  }
  return 0;
}