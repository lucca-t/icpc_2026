#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
    int n; cin>>n;
    vector<int> height;
    for(int i=0; i<n; i++){
       int a; cin>>a; height.push_back(a);
    }
    int l = 0; 
    int d = height.size()-1; 
    int max_l = height[l]; int max_d = height[d];
    ll ans = 0;
    ll aux = 0;
    while(l != d){
        if(height[l] <= height[d]){
            l++;
            max_l = max(max_l, height[l]);
            if(max_l - height[l] == 0){
                ans = max(ans, aux);
                aux = 0;
            }
            else{
                aux += abs(max_l - height[l]);
            }
        }
        else{
            d--;
            max_d = max(max_d, height[d]);
            if(max_d - height[d] == 0){
                ans = max(ans, aux);
                aux = 0;
            }
            else{
                max_d = max(max_d, height[d]);
                aux += abs(max_d - height[d]);
            }
        }
    }
    cout<<ans<<endl;
}
