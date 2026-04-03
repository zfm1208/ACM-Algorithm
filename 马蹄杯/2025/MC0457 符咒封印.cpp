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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
/*
    拿到题目没有思路，我们看看数据范围
    区间查询问题，没有修改，往O(1)时间复杂度去想
    首选前缀和->区间问题
    然后我们把式子进行推导
    把式子写成数学求和公式
    然后移项， 把式子化简成可以前缀和的形式
    然后最后取模时注意+mod
*/
void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> pre(n+1),sum(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = (pre[i-1] + i * a[i] % mod) % mod;
        sum[i] = (sum[i-1] + a[i]) % mod;
    }
    while(q--){
        int l,r; cin >> l >> r;
        int ans = ((pre[r] - pre[l-1] + mod) % mod - (l-1) * (sum[r] - sum[l-1]) % mod  + mod) % mod;
        cout << ans << endl;
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