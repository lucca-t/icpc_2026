#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  // inputs
  int t;
  cin >> t;

  // ONE INDEXED
  for (int i = 0; i < t; ++i) { // test cases
    int n;                      // string of length n
    cin >> n;
    vector<bool> printed(
        n + 1, 0); // this is where we'll print all the ones that are missing
    // printed will be 1 based
    // true = printed false = not
    string s;
    cin >> s;
    stack<int> memory;

    // Go thru string
    for (int i = 0; i < s.length(); i++) {
      // one indexed so plus 1
      int idx = i + 1;
      if (s[i] == '1') {        // add to memory
        memory.push(idx);       // it's the idx (1 based) not i(0 based)
      } else if (s[i] == '2') { // print from stack or at that idx
        if (!memory.empty()) {
          printed[memory.top()] = true;
          memory.pop();
        } else {
          printed[idx] = true;
        }
      } else { // it's a 3
        printed[idx] = true;
      }
    }

    // output
    int count = -1;
    for (bool print : printed) { // if false, count ++
      if (!print)
        count++;
    }
    cout << count << "\n";
    for (int i = 1; i < printed.size(); i++) {
      // if false print idx;
      if (!printed[i]) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
}
