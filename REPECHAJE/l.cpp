#include <bits/stdc++.h>
typedef vector<string> vi;
#define PB push_back

using namespace std;
int main() {
    // solution comes here
    int n; cin >> n;
    vi lista(n);
    for(int i = 0; i < n; ++i){
        string str; cin >> str;
        lista.PB(str);
    }

    for(string str: lista){
        cout<<str<<endl;
    }
}