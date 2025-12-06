#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

const int max_digits = 12;
const ll powers_of_10[max_digits + 1] = {1,
                                         10,
                                         100,
                                         1000,
                                         10000,
                                         100000,
                                         1000000,
                                         10000000,
                                         100000000,
                                         1000000000,
                                         10000000000LL,
                                         100000000000LL,
                                         1000000000000LL};

unordered_set<ll> all_numbers;
void generate(int repetition) {
  int max_digits_partition = max_digits / repetition;
  for (int i = 1; i < powers_of_10[max_digits_partition]; i++) {
    int i_size = [](int x) {
      int ans = 0;
      while (x) {
        x /= 10;
        ans++;
      }
      return ans;
    }(i);

    ll number = 0;
    for (int j = 0; j < repetition; j++) {
      number *= powers_of_10[i_size];
      number += i;
    }
    all_numbers.insert(number);
  }
}

int main() {
  for (int i = 2; i <= max_digits; i++)
    generate(i);

  string line;
  cin >> line;

  vector<string> ranges = split(line, ',');

  vector<pair<ll, ll>> splitted_ranges(ranges.size());
  transform(ranges.begin(), ranges.end(), splitted_ranges.begin(),
            [](string x) {
              vector<string> values = split(x, '-');
              return make_pair(stoll(values[0]), stoll(values[1]));
            });

  ll ans = 0;
  for (auto number : all_numbers) {
    for (auto range : splitted_ranges) {
      if (number >= range.first && number <= range.second)
        ans += number;
    }
  }
  cout << ans << '\n';
  return 0;
}
