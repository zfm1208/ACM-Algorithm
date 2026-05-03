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

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end());
    int ans = m;
    int time = 0; // 经过时间
    int cnt = 0; // 手里士兵
    int op = 1; // 每秒产出
    // 假设最后只要i个堡垒
    for(int i = 1; i <= n; i++){
        int ct = 0;
        if(cnt < a[i]){
            ct = (a[i] - cnt + op - 1) / op;
        }
        time += ct;
        if(time > m) break;
        cnt += ct * op;
        cnt -= a[i];
        op++;
        int res = cnt + op * (m - time);
        // cout << "i : " << i << " res: " << res << endl;
        ans = max(ans, res);
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