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
const int N = 2e5 + 5;

void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> b(n+1),pre(n+1);
    for(int i = 3; i <= n; i++){
        if(a[i-2] >= a[i-1] && a[i-1] >= a[i]) b[i] = 1;
    }
    for(int i = 2; i <= n; i++){
        pre[i] = pre[i-1] + b[i];
    }
    while(m--){
        int l,r; cin >> l >> r;
        int len = r - l + 1;
        if(len <= 2) {
            cout << len << endl;
            continue;
        }
        int ans = pre[r] - pre[l+1];
        cout << len - ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
