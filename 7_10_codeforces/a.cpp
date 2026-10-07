#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  // inputs
  ll n;
  cin >> n;
  // vector<int> v;

  for (ll i = 1; i < n + 1; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    // cout << "x, y , r" << x << ", " << y << ", " << r << "\n";
    //  output any coordinate that's R away from x,y

    cout << x + r << " " << y << "\n";
  }
}