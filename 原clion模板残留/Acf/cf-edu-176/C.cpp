//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n, m;cin >> n >> m;
    vector<int> a(m);
    rep(i,0,m-1)cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(m);
    vector<int> pre(m + 1, 0);
    rep(i,0,m-1){
        b[i] = min(a[i], n - 1);
        pre[i + 1] = pre[i] + b[i];
    }
    int sum = 0;
    for(int i = 0; i < m; i++){
        int x = n - a[i];
        if (x > n - 1)continue;
        int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        int mn = pre[m] - pre[pos];
        int cnt = m - pos;
        if(a[i] >= x){
            mn -= b[i];
            cnt -= 1;
        }
        if(cnt <= 0) continue;
        int res = mn + cnt * (1 - max(x, 1ll));
        if(res > 0)sum += res;
    }
    cout << sum << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
