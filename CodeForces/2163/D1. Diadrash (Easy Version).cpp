#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve(){
    int n, q;
    cin >> n >> q;
    vector<pii> v(q);
    for(int i = 0; i < q; i++){
        int l,r; cin >> l >> r;
        v[i] = {l,r};
    }
    int bound = max(300LL, (int)ceil(n / 2.) + 2);
    auto ask = [&](int l, int r) -> int {
        cout << "?" << " " << l << " " << r << endl;
        int res;
        cin >> res;
        return res;            
    };
    sort(v.begin(), v.end());
    vector<pii> vv;
    for(int i = 0; i < v.size(); i++){
        if(vv.size() > 0){
            auto [l1, r1] = vv.back();
            auto [l2, r2] = v[i];
            if(l1 == l2){
                vv.pop_back();
                vv.pb(v[i]);
            } else if(l2 > l1 && r2 > r1){
                vv.pb(v[i]);
            } else {
                continue;
            }
        } else {
            vv.pb(v[i]);
        }
    }
    if(vv.size() <= bound + 20){
        int ans = 0;
        int bl = 0, br = n;
        for(auto [l, r] : vv){
            if(l > br || r < bl) continue;
            int op = ask(l, r);
            if(op > 0){
                bl = max(l, bl);
                br = min(r, br);
            }
            ans = max(ans, op);
        }
        cout << "!" << " " << ans << endl;
    } else {
        int l = 0, r = n + 1;
        while(l + 1 < r){
            int mid = l + r >> 1;
            if(ask(1, mid) > 0) r = mid;
            else l = mid;
        }
        int pos = r;
        for(int i = 0; i < vv.size(); i++){
            auto [l, r] = vv[i];
            if(l > pos || r < pos) continue;
            v.pb(vv[i]);
        }
        int ans = 0;
        int bl = 0, br = n;
        for(auto [l, r] : v){
            if(l > br || r < bl) continue;
            int op = ask(l, r);
            if(op > 0){
                bl = max(l, bl);
                br = min(r, br);
            }
            ans = max(ans, op);
        }
        cout << "!" << " " << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}