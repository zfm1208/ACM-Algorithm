#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 1100000;
/*
    身高一样的猫不能相邻
    两只身高相邻的猫之间必须要有一直身高低于他们的猫
    20 19 18 ... 3 2 1 2 3 4 5... 18 19 20 19 18 ..
    .. 5 4 3 4 5 6 .. 18 19 20 19 18 .. 6 5 6 7 .. 

    n = 15 = 2^4-1  (1-4)
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    4 3 4 2 4 3 4 1 4 3  4  2  4  3  4
      3   2       1         2     3
    1  1 = 2^0 ；8 
    2  2 = 2^1 : 4 12 (+8)
    3  4 = 2^2 : 2 6 10 14 (+4)
    4  8 = 2^3 : 1 3 5 7 9 11 13 15 (+2)
    2^20 - 1 = 1048576 - 1 ~= 1e6
*/
int ans[N];
void solve(){
    int n; cin >> n;
    for(int k = 0; k < 20; k++){
        for(int i = (1 << k); i <= n; i +=(1<<(k+1))){
            ans[i] = (20 - k);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}