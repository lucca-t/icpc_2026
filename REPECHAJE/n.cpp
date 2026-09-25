#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long int;

ull triangular(ull n){
    ull x = floor(sqrt(2*n));
    if(x*(x+1) <= 2*n){
        return x;
    }
    else{
        return x-1;
    }
}

int main(){
    ull l, r; cin >> l >> r;
    cout << triangular(r) - triangular(l - 1) << "\n";
}
