#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e5, mod = 1e9+7, inf = 1e18 + 5;
struct BIT {
    vector<int> tr;
    int n;
    BIT(int _n) : n(_n), tr(_n + 1) {}
    int low_bit(int x) { return x & (-x); }
    void add(int x, int val) {
        for(int i = x; i <= n; i += low_bit(i)){
            tr[i] += val;
        }
    }

    int query(int x) {
        if(x > n) x = n;
        int res = 0;
        for(int i = x; i > 0; i -= low_bit(i)) {
            res += tr[i];
        }
        return res;
    }

    int query(int l, int r) {
        if(l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct node {
    int l, r, k, id;
};
void solve(){
    int n,q; cin >> n >> q;
    vii a(n + 1), ans(q + 1);
    rep(i, 1, n) cin >> a[i];
    int sq = sqrt(N);
    vector<vector<node>> qs(sq+1);
    vector<vector<pii>> qs1(n+1);
    for(int i = 1; i <= q; i++){
        int l, r, k; 
        cin >> l >> r >> k;
        if(k <= sq){
            qs[k].push_back({l, r, k, i});
        }else{
            qs1[r].push_back({k, i});
            qs1[l-1].push_back({k, -i});
        }
    }
    vii pre(n + 1);
    for(int k = 1; k <= sq; k++){
        if(qs[k].empty()) continue;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1] + a[i] / k;
        }
        for(auto &it: qs[k]){
            ans[it.id] = pre[it.r] - pre[it.l - 1];
        }
    }

    BIT bit(N + 5);
    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) bit.add(a[i], 1);
        for(auto &[k,id] : qs1[i]){
            int m = N / k;
            int sum = 0;
            for(int j = 1; j <= m; j++){
                int L = j * k;
                int R = (j + 1) * k - 1;
                sum += j * (bit.query(L, R));
            }
            if(id > 0) ans[id] += sum;
            else ans[-id] -= sum;
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