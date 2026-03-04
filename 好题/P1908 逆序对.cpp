#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) : n(_n), tr(_n + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> b;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b.pb(a[i]);
    }
    // 离散化 - 排序,去重,二分
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i = 1; i <= n; i++){
        // lower_bound 找到相对大小，+1 是因为树状数组下标必须从 1 开始
        a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
    }
    BIT bit(b.size());
    int ans = 0;
    for(int i = n; i >= 1; i--){
        ans += bit.query(a[i] - 1);
        bit.add(a[i],1);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}