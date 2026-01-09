//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int head[N], cnt;
struct Edge{
    int to;
    int w;
    int next;
}e[N * 2];
void add(int u, int v, int w){
    ++cnt;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void solve() {
    int n,m; cin >> n >> m;
    cnt = 0;
    memset(head, -1, sizeof head);
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        add(v,u,0);
    }
    vector<bool> vis(n+1,false);
    vector<int> ans(n+1,0);
    for(int u = n; u >= 1; u--){
        if(!vis[u])
        {
            queue<int> q;
            q.push(u);
            vis[u] = true;
            ans[u] = u;
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                for(int i = head[x]; i != -1; i = e[i].next)
                {
                    int v = e[i].to;
                    if(!vis[v]){
                        vis[v] = true;
                        ans[v] = u;
                        q.push(v);
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
