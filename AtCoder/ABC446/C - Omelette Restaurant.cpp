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
    int n,d; cin >> n >>d;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    deque<pii> dq;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        dq.pb({i,a[i]});
        ans += a[i];
        int tot = b[i];
        while(tot && !dq.empty()){
            if(dq.front().se <= tot){
                tot -= dq.front().se;
                ans -= dq.front().se;
                dq.pop_front();
            }else{
                dq.front().se -= tot;
                ans -= tot;
                tot = 0;
            }
        }
        while(!dq.empty()){
            if(i - dq.front().fi  < d) break;
            ans -= dq.front().se;
            dq.pop_front();
        }
    }
    cout << ans << endl;
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