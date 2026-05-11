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
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> dist(n+1, inf);
    vector<int> vis(n+1);
    int ans = 0;
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        int u = -1;
        int mn = inf;
        for(int j = 1; j <= n; j++){
            if(vis[j] == 0 && dist[j] < mn){
                mn = dist[j];
                u = j;
            }
        }
        vis[u] = 1;
        ans += mn;
        for(int v = 1; v <= n; v++){
            if(vis[v]) continue;
            int cost = 0;
            if((u+v) & 1){
                cost = a[(u+v)/2] + a[(u+v+1)/2];
            }else{
                cost = 2 * a[(u+v)/2];
            }
            if(cost < dist[v]){
                dist[v] = cost;
            }
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