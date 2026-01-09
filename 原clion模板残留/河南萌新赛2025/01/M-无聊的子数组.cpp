// O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
// O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7, mod2 = 998244353, inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int inv2 = 5e8 + 4;
int n, q;
vector<int> a(N);
vector<pii> adj[N];
map<int, int> col[N]; // 颜色，val
int fa[N];

void dfs(int u,int f){
    fa[u] = f;
    for(auto &[v,w] : adj[u]){
        if(v!= f){
            col[u][a[v]] += w;
            dfs(v, u);
        }
    }
}


void solve()
{
    cin >> n >> q;
    // 存每个node所连的结点的颜色的贡献
    // 方便查询后的修改
    // 存每个node之间的val
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map<pii, int> mp;
    // 建树，子节点和父节点按大小存
    int ans = 0;
    for (int i = 1; i < n; i++){
        int u, v, val;
        cin >> u >> v >> val;
        adj[u].pb({v, val});
        adj[v].pb({u, val});
        if(a[u] != a[v]){
            ans += val;
        }
        if(u > v){
            swap(u, v);
        }
        mp[{u, v}] = val;
    }
    // dfs 求每个结点的孩子的颜色的贡献
    dfs(1, 0);
    // 由于dfs能求的是每个结点的孩子贡献，而父亲不囊括，所以，另判一下就行了
    while(q--){
        int u, x;
        cin >> u >> x;
        if(x == a[u]){
            cout << ans << endl;
        }else{
            int dad = fa[u];
            if(u != -1){
                // 若该节点和它dad的颜色一样
                if(a[u] == a[dad]){
                    ans += mp[{dad, u}];
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    //    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
