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
    看到数据范围，O(n)的时间复杂度去解决，大概率是打表找规律
*/
void solve(){
    int n; cin >> n;
    int ans = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        int x = a[i] * (pre[i-1] + 1) % mod;
        ans = (ans + x) % mod;
        pre[i] = (pre[i-1] + x) % mod;
    }

    cout << ans << endl;
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