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
unordered_map<int,int> mpa,mpb;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n+1), b(m+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) {
        cin >> b[i];
        mpb[b[i]]++;
    }
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        int x = a[i];
        if(mpa[x] < mpb[x]) cnt++;
        mpa[x]++;
        if(i > m){
            int y = a[i - m];
            if(mpa[y] <= mpb[y]) cnt--;
            mpa[y]--;
        }
        if(i >= m){
            if(cnt >= k) ans++;
        }
    }
    cout << ans << endl;
    mpa.clear(),mpb.clear();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}