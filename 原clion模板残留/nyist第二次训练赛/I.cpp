//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 1e8 + 5;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    int m; cin >> m;
    vector<int> b(n),pre(n);
    for(int i = 1; i < n; i++){
        b[i] = a[i + 1] - a[i];
    }
    sort(b.begin()+1, b.end());
    for(int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + b[i] - 1;
    }
    while(m--){
        int l,r; cin >> l >> r;
        int len = r - l;
//        for(int i = 1; i < n; i++){
//            int x = a[i] - a[i-1];
//            if(x>len) x = len;
//            ans += x;
//        }
        auto pos = upper_bound(b.begin()+1, b.end(), len) - b.begin();
        int ans = pre[pos - 1] + (n - pos) * len + len + n;
        cout << ans << " \n"[m == 0];
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
// 1  1  3  4  5  9
// 0  1` 2  3  4  5  6  7  8  9  10
// 1  2  3  4  5  6  7  8  9  10 11

// 1  2  3  4  5  6  7  8  9  10 11
// 3  4  5  6  7  8  9  10 11 12 13
// 4  5  6  7  8  9  10 11 12 13 14
// 5  6  7  8  9  10 11 12 13 14 15
// 9  10 11 12 13 14 15 16 17 18 19
//   1 3 4 5 9
//10+2+1+1+4