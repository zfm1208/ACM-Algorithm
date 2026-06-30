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
const int N = 1e6, mod = 1e9+7, inf = 1e18+5;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> fa(n+1), siz(n+1, 1), cun;
    stack<int> st;
    st.push(1);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cun.pb(u);
        for(auto v : g[u]){
            if(v == fa[u]) continue;
            fa[v] = u;
            st.push(v);
        }
    }
    for(int i = cun.size() - 1; i >= 0; i--){
        int u = cun[i];
        for(auto v : g[u]){
            if(fa[v] == u){
                siz[u] += siz[v];
            }
        }
    }
    int ans = 0;
    for(int u = 1; u <= n; u++){
        int rt = sqrt(a[u]);
        if(rt * rt != a[u]) continue;
        int sum1 = 0,sum2 = 0,sum3 = 0;
        for(auto v : g[u]){
            int s;
            if(fa[v] == u) s = siz[v];
            else s = n - siz[u];
            sum3 += sum2 * s;
            sum2 += sum1 * s;
            sum1 += s;
        }
        // cout << sum1 << " " << sum2 << " " << sum3 << endl;
        ans += sum2+sum3;
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