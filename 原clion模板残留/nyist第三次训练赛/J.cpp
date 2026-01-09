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
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int cnt = 0;
    int l = 0;
    while(l < n){
        int r = l;
        while (r + 1 < n && a[r + 1] == a[l]) r++;
        bool flag = true;
        if((l > 0 && a[l - 1] <= a[l]) ||(r < n - 1 && a[r] >= a[r + 1]) ) flag = false;
        if(flag) cnt++;
        l = r + 1;
    }
    cout << (cnt == 1 ? "YES": "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}