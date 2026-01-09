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
void solve() {
    int n,q; cin >> n >> q;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    while(q--)
    {
        int l,r,s; cin >> l >> r >> s;
        int last = 0,ans = 0,ok = 0;
        while(l <= r){
            int L = min(l+last,r),R = r;
            int pos = -1;
            while(L <= R){
                int mid = (L + R) >> 1;
                if(pre[mid] - pre[l-1] >= s){
                    pos = mid;
                    R = mid - 1;
                }else L = mid + 1;
            }
            if(pos == -1){
                cout << ans << " " << pre[r] - pre[l-1] << endl;
                ok = 1;break;
            }
            int len = pos - l + 1;
            last = len;
            int LL = 1,RR = (r-l+1) / len + 1;
            int cnt = 0; // 有相同len的个数cnt
            // [l,r] .....[st,ed]
            //       mid个
            while(LL <= RR){
                int mid = (LL + RR) >> 1;
                int st = l + (mid - 1) * len;
                int ed = min(l + mid * len - 1, r);
                if(st <= r && pre[ed] - pre[st-1] >= s){
                    cnt = mid;
                    LL = mid + 1;
                }else RR = mid - 1;
            }
            ans += cnt;
            l += cnt * len;
        }
        if(!ok) cout << ans << " " << 0 << endl;
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