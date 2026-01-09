//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int n; cin >> n;
    vector<pii> a(n+1);
    vector<int> pre(n+1),ans(n+1);
    int l = 0,x; // l当前能处理的最远位置
    rep(i,1,n)cin >> x,a[i] = {x,i};
    sort(a.begin()+1,a.end());
    pre[0] = 0;
    rep(i,1,n) pre[i] = pre[i-1] + a[i].fi;
    rep(i,1,n) {
        if (l < i) { // 如果当前指针未覆盖i，则从i开始扩展
            l = i;
            // 尽可能扩展l，直到无法满足条件或越界
            while (l < n && pre[l] >= a[l+1].fi) {
                l++;
            }
        }
        ans[a[i].se] = l; // 记录结果（原位置对应的答案）
    }
    // 输出答案，每个答案减1（初始元素不计入）
    rep(i,1,n) cout << ans[i] - 1 << " \n"[i==n];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}