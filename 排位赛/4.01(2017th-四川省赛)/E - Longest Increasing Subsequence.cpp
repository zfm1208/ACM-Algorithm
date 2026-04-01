#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    LIS (a[1],a[2],...,a[n])
    = f[1] * f[1] xor f[2] * f[2] xor ... xor f[n] * f[n]; 

    for i in [1,2, .. n]
      f[i] = 1
        for j in [1,2,... i-1]
            if (a[j] < a[i]) 
            f[i] = max(f[i], f[j] + 1)

    LIS(i) 删掉第i个元素后的序列的 LIS

    5
    2 5 3 1 4

    5 3 1 4
    f[1] = 1
    f[2] = 2    
    f[3] = 3
    f[4] = 2

    LIS(1) = 1 ^ 4 ^ 9 ^ 4

*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> f(n+1,vector<int>(2));

    for(int i = 1; i <= n; i++){
        f[i][0] = 1;
        for(int j = 1; j < i; j++){

        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}