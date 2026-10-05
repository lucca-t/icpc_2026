#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
 
struct Mat {
    int n, m;
    vector<vector<int>> a;
    Mat() { }
    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        a.assign(n, vector<int>(m, 0));
    }
    Mat(vector<vector<int>> v) {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }
    inline void make_unit() {
        assert(n == m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = (i == j);
            }
        }
    }
    inline Mat operator * (const Mat &b) {
        assert(m == b.n);
        Mat ans(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    ans.a[i][j] =
                        (ans.a[i][j]
                        + 1LL * a[i][k] * b.a[k][j] % mod)
                        % mod;
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k) {
        assert(n == m);
        Mat ans(n, n);
        Mat t = *this;
        ans.make_unit();
        while(k){
            if(k & 1){
                ans = ans * t;
            }
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
};
 
int main(){
    ll n;
    cin>>n;
    if(n == 0){
        cout<<1<<endl;
        return 0;
    }
 
    if(n == 1){
        cout<<2<<endl;
        return 0;
    }
    if(n == 2){
        cout<<3<<endl;
        return 0;
    }
 
    Mat M({
        {3, 2, 1, 3},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    });
 
    Mat base({
        {3},
        {2},
        {1},
        {1}
    });
 
    Mat result = M.pow(n - 2)*base;
 
    cout<<result.a[0][0]<<endl;
}
