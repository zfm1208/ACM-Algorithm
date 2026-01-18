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
/*
    把所有机器人当成一个整体，整体移动，
    对于每个机器人i，找最近得尖刺并记距离
*/
void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n+1),b(m+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    string s; cin >> s; s = " " + s;
    vector<int> ans(k+1);
    sort(b.begin()+1,b.end());
    sort(a.begin()+1,a.end());
    vector<pii> L(n+1),R(n+1);
    for(int i = 1; i <= n; i++){
        int posr = lower_bound(b.begin()+1,b.end(),a[i]) - b.begin();
        if(1 <= posr && posr <= m) R[i] = {b[posr]-a[i], i};
        else R[i] = {inf, i};

        int posl = posr - 1;
        // cout << posr << " " << posl << endl;
        if(1 <= posl && posl <= m) L[i] = {a[i]-b[posl], i};
        else L[i] = {inf, i};
    }
    // for(int i = 1; i <= n; i++){
    //     cout << L[i].fi << " " << R[i].fi << endl;
    // }
    sort(L.begin()+1,L.end());
    sort(R.begin()+1,R.end());
    vector<int> vis(n+1);
    int now = 0; 
    int l = 1,r = 1;
    int cnt = n;
    for(int i = 1; i <= k; i++){
        if(s[i] == 'L') now--;
        else now++;
        int dist = abs(now);
        // cout << "now: " << now << endl;
        if(now > 0){
            while(r <= n && R[r].fi <= dist){
                if(!vis[R[r].se]){
                    vis[R[r].se] = 1;
                    cnt--;
                }
                r++;
            }
        }else{
            while(l <= n && L[l].fi <= dist){
                if(!vis[L[l].se]){
                    vis[L[l].se] = 1;
                    cnt--;
                }
                l++;
            }
        }
        ans[i] = cnt;
    }
    rep(i,1,k) cout << ans[i] << " \n"[i==k];
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