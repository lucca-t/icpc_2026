#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 3;
  for (ll i = 3; i < n + 1; i++) {
    dp[i] =
        ((3 * dp[i - 1] % mod) + (2 * dp[i - 2] % mod) + dp[i - 3] + 3) % mod;
  }
  cout << dp[n] << endl;
}