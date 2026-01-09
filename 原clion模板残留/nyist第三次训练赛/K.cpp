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
//  01串逆序对问题
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i,1,n){cin >> a[i];b[i] = b[i - 1] + a[i];}
    int cnt = 0;
    // 不修改时的逆序对数量
    for (int i = 1; i <= n; i++) {
        if (a[i]) cnt += (n - i) - (b[n] - b[i]);
    }
    int ans = cnt;
    // 若修改一次的逆序对数量，与 不修改时的逆序对数量比较，取较大值
    for (int i = 1; i <= n; i++){
        int sum = (n - i) - (b[n] - b[i]);
        int mid = b[i - 1];
        if(a[i]) ans = max(ans, cnt - sum + mid);
        else ans = max(ans, cnt - mid + sum);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
