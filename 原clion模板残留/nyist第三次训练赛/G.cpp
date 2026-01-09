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
    int n; cin >> n;
    vector<int> a(n+1),pre(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) pre[i] = pre[i-1] + a[i];
    int p = 1,ans = 0;
    while(p <= n && a[p]!=0) p++;
    rep(i,1,p-1)if(!pre[i]) ans++;
    while(p <= n){
        int p1 = p+1;
        while(p1 <= n && a[p1]!=0) p1++;
        map<int,int> mp;
        int mx = 0;
        for(int i = p; i < p1; i++){
            mp[pre[i]]++;
            mx = max(mx,mp[pre[i]]);
        }
        ans += mx;
        p = p1;
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
