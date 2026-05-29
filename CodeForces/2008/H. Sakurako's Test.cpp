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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n,q; cin >> n >> q;
    vii a(n+1),pre(n+1),ans(n+1, -1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre[x]++;
    }
    for(int i = 1; i <= n; i++){
        pre[i] += pre[i-1];
    }
    auto get = [&](int l, int r) -> int {
        if(l > r) return 0;
        r = min(r, n);
        l = max(l, 1LL);
        return pre[r] - pre[l-1];
    };
    while(q--){
        int x; cin >> x;
        if(ans[x] != -1) {
            cout << ans[x] << " ";
            continue;
        }
        int l = 0, r = x - 1;
        int res = x - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int cnt = 0;
            for(int k = 0; k * x <= n; k++){
                cnt += get(k*x, k*x + mid);
            }
            if(cnt >= n / 2 + 1){
                res = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        ans[x] = res;
        cout << ans[x] << " ";
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}