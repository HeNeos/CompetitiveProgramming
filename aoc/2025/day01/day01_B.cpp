#include <bits/stdc++.h>
using namespace std;

int main() {
  string direction;
  int current_position = 50;
  int ans = 0;
  while (cin >> direction) {
    int position;
    cin >> position;
    if (direction == "R") {
      current_position += position;
      ans += current_position / 100;
      current_position %= 100;
    } else {
      if (current_position == 0)
        current_position = 100;
      current_position -= position;
      if (current_position < 0)
        ans += (abs(current_position) + 100 - 1) / 100;
      current_position %= 100;
      if (current_position < 0)
        current_position += 100;
      if (current_position == 0)
        ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
