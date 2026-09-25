#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  // inputs
  ll n, q;
  cin >> n >> q;
  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    v.push_back(a);
  }

  // llenar con minimos
  vector<ll> ans(n, -1e9);
  ll i = n - 1;
  ans[i] = v[i];
  ll sum = ans[i];
  i--;

  // -2 3 -1 4 -5
  //       4  4  -5

  while (i >= 0) {
    sum = max(v[i], sum + v[i]);
    ans[i] = max(sum, ans[i + 1]);
    i--;
  }
  for (ll i = 0; i < q; i++) {
    ll b;
    cin >> b;
    cout << ans[b] << endl;
  }
}