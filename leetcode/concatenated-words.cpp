#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct Node {
    int nextNode[26];
    bool isOutput = false;
    Node() { fill(begin(nextNode), end(nextNode), -1); }
  };
  void addString(vector<Node> &trie, string &s) {
    int nodeId = 0;
    for (auto c : s) {
      int cValue = (int)(c - 'a');
      if (trie[nodeId].nextNode[cValue] == -1) {
        trie[nodeId].nextNode[cValue] = trie.size();
        trie.emplace_back();
      }
      nodeId = trie[nodeId].nextNode[cValue];
    }
    trie[nodeId].isOutput = true;
  }
  int searchString(vector<Node> &trie, string &s, int lastNode = 0,
                   int position = 0) {
    int nodeId = lastNode;
    for (int i = position; i < s.size(); i++) {
      int c = (int)(s[i] - 'a');
      if (trie[nodeId].nextNode[c] == -1)
        return -1;
      nodeId = trie[nodeId].nextNode[c];
    }
    return nodeId;
  }
  unordered_map<int, int> cache;
  int longestComposition(vector<Node> &trie, string &s, int startPosition = 0,
                         int currentCount = 0) {
    if (cache.find(startPosition) != cache.end())
      return cache[startPosition];
    if (startPosition == s.size())
      return currentCount;
    string prefix = "";
    int ans = -1;
    int lastNode = 0;
    for (int i = startPosition; i < s.size(); i++) {
      prefix += s[i];
      lastNode = searchString(trie, prefix, lastNode, prefix.size() - 1);
      if (lastNode == -1) {
        break;
      }
      if (trie[lastNode].isOutput) {
        int out = longestComposition(trie, s, i + 1, currentCount + 1);
        ans = max(ans, out);
      }
    }
    cache[startPosition] = ans;
    return ans;
  }
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    vector<Node> trie(1);
    for (auto word : words)
      addString(trie, word);
    vector<string> ans;
    for (auto word : words) {
      cache.clear();
      int x = longestComposition(trie, word, 0);
      if (x >= 2)
        ans.push_back(word);
    }
    return ans;
  }
};
