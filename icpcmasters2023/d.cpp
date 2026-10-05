#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> trap(vector<int> &height) {
  int n = height.size();
  if (n == 0) {
    return {0};
  }
  int l = 0, r = n - 1;
  int leftmax = height[l], rightmax = height[r];
  vector<int> resarray(n);
  while (l < r) {
    if (leftmax < rightmax) {
      l++;
      leftmax = max(height[l], leftmax);
      resarray[l] = leftmax - height[l];
    } else {
      r--;
      rightmax = max(height[r], rightmax);
      resarray[r] = rightmax - height[r];
    }
  }
  return resarray;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> height(n);
  for (int i = 0; i < n; i++) {
    int h = 0;
    cin >> h;
    height[i] = h;
  }
  vector<int> wata = trap(height);

  ll maxwater = 0;
  ll currwater = 0;
  for (int i = 0; i < wata.size(); i++) {
    if (wata[i] == 0) {
      currwater = 0;
    } else {
      currwater += wata[i];
    }
    maxwater = max(maxwater, currwater);
  }
  // for (int num : wata) {
  //   cout << num << ", ";
  // }
  // cout << "\n";
  // cout << "balls\n";
  cout << maxwater << "\n";

  return 0;
}