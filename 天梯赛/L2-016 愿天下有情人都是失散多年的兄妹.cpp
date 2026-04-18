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
struct node {
    char six;
    int fa,ma;
}p[N];
int vis[N];
bool falg;
void dfs1(int u, int dep) {
    if(u == -1 || dep > 5) return;
    vis[u] = 1;
    dfs1(p[u].fa, dep + 1);
    dfs1(p[u].ma, dep + 1);
}

void dfs2(int u, int dep) {
    if(u == -1 || dep > 5) return;
    if(falg) return;
    if(vis[u]){
        falg = 1;
        return;
    }
    dfs2(p[u].fa, dep + 1);
    dfs2(p[u].ma, dep + 1);  
}
void solve(){
    int n; cin >> n;
    for(int i = 0; i < N; i++){
        p[i].fa = p[i].ma = -1;
        p[i].six = 0;
    }
    for(int i = 1; i <= n; i++){
        int id,fa,ma; char six;
        cin >> id >> six >> fa  >> ma;
        p[id] = {six,fa,ma};
        if(fa != -1) p[fa].six = 'M';
        if(ma != -1) p[ma].six = 'F';
    }
    int k; cin >> k;
    while(k--){
        int a,b; cin >> a >> b;
        if(p[a].six == p[b].six) {
            cout << "Never Mind\n";
            continue;
        }
        memset(vis, 0, sizeof(vis));
        falg = false;
        dfs1(a, 1);
        dfs2(b, 1);
        if (falg) {
            cout << "No\n"; 
        } else {
            cout << "Yes\n";
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