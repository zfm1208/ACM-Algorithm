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
void Fi(int n, int m){
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    // bfs求顶点到1的最短距离
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    string ans;
    // r-0 g-1 b-2
    for(int i = 1; i <= n; i++){
        if(dist[i] % 3 == 0){
            ans += 'r';
        }else if(dist[i] % 3 == 1){
            ans += 'g';
        }else{
            ans += 'b';
        }
    }
    cout << ans << endl;
}
void SE(int q){
    while(q--){
        int d; cin >> d;
        string s; cin >> s;
        int r=0,g=0,b=0;
        s = " " + s;
        int pr=0,pg=0,pb=0;
        for(int i = 1; i <= d; i++){
            if(s[i] == 'r') r=1,pr=i;
            else if(s[i] == 'g') g=1,pg=i;
            else b=1,pb=i;
        }
        if(r&&b) cout << pr << endl;
        else if(r && g) cout << pg << endl;
        else if(g && b) cout << pb << endl;
        else cout << 1 << endl;
    }
}
void solve(){
    string s; cin >> s;
    int t; cin >> t;
    while(t--){
        if(s == "first"){
            int n,m; cin >> n >> m;
            Fi(n,m);
        }else{
            int q; cin >> q;
            SE(q);
        }
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