//
// Created by zfm25 on 2025/7/17.
//
// O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
// O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7, mod2 = 998244353, inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int inv2 = 5e8 + 4;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> dp(n + 10), dp1(n + 10);
    vector<int> pre(n + 10 , -inf), suf(n + 10 , -inf);
    for (int i = 1; i <= n; i++){
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        pre[i] = max(pre[i - 1], dp[i]);
    }
    for (int i = n; i >= 1; i--){
        dp[i] = max(a[i], dp[i + 1] + a[i]);
        suf[i] = max(suf[i + 1], dp[i]);
    }
    int ans = -inf;
    for (int i = 1; i < n; i++){

        ans = max(ans, pre[i] + suf[i+1]);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    //    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
