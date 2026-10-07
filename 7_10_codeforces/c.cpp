#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  // inputs
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) { // t test cases
    // INPUT
    int n;
    cin >> n;
    vector<int> love(n, 0);
    for (int j = 0; j < n; j++) {
      int lov;
      cin >> lov;
      love[j] = lov;
    }

    /**
     * [0,1,2,3,4,5,6]
     * [1, ,1, ,1]
     * [,]
     */
    // store the sum  as the key
    // store the triads as a set
    // check sum first, if it has any repeats then don't add
    unordered_map<ll, int> counts; // {sum, count}
    ll ans = 0;
    // COMBINATIONS
    for (int x = 0; x < n - 4; x++) {
      // x, x+2, x+4 triad
      ll sum = love[x] + love[x + 2] - love[x + 4];
      int add = 0;
      if (counts.contains(sum)) {
        add = counts[sum];
        // calc x -2 and x - 4
        if ((x >= 2) && (love[x - 2] + love[x] - love[x + 2]) == sum)
          add--;
        if ((x >= 4) && (love[x - 4] + love[x - 2] - love[x]) == sum)
          add--;
      }
      ans += add;
      counts[sum]++;
    }
    cout << ans << "\n";
  }
}