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
    int find(int k){
        int pos = 0;
        for (int i = 19; i >= 0; i--) {
            if (pos + (1 << i) <= n && tr[pos + (1 << i)] < k) {
                pos += (1 << i);
                k -= tr[pos];
            }
        }
        return pos + 1;
    }
};

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1),cnt(m+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mxc = 0;
    for(int i = 1; i <= m; i++){
        mxc = max(mxc, cnt[i]);
    }
    // fre[i] = {{},{},{}}
    // 存储频率为i的数字
    vector<vector<int>> freq(mxc+1);
    for(int i = 1; i <= m; i++){    
        freq[cnt[i]].pb(i);
    }
    vector<int> sum(mxc),pre(mxc);
    int tot = 0;
    for(int k = 0; k < mxc; k++){
        tot += freq[k].size();
        sum[k] = tot;
        pre[k] = (k == 0 ? 0 : pre[k-1]) + sum[k];
    }
    int k = (mxc == 0 ? 0 : pre[mxc-1]);
    int q; cin >> q;
    vector<int> ans(q+1);
    vector<vector<pii>> qs(mxc);
    for(int i = 1; i <= q; i++){
        int x; cin >> x;
        if(x <= n) ans[i] = a[x];
        else{
            x -= n;
            if(x > k){
                ans[i] = (x - k - 1) % m + 1;
            }else{
                int it = lower_bound(pre.begin(),pre.end(),x) - pre.begin();
                int rem;
                if(it == 0) rem = x;
                else rem = x - pre[it-1];
                qs[it].pb({rem,i});
            }
        }   
    }
    BIT bit(m);
    for(int k = 0; k < mxc; k++){
        for(int v: freq[k]){
            bit.add(v,1);
        }
        for(auto [rem,id]: qs[k]){
            ans[id] = bit.find(rem);
        }
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << endl;
    }
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