//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define uint unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n)cin >> a[i];
    vector<int> pre(n+1), suf(n+1);
    if(a[1] > 0) pre[1] = a[1];
    for(int i = 2; i <= n; i++){
        pre[i] = pre[i - 1];
        if(a[i] > 0) pre[i] += a[i];
    }
    if(a[n] < 0) suf[n] = -a[n];
    for(int i = n - 1; i >= 1; i--){
        suf[i] = suf[i + 1];
        if(a[i] < 0) suf[i] -= a[i];
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max(mx, pre[i] + suf[i]);
    cout << mx << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
