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
struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
        }
    }
};

void solve(){
    int n,m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int op,x,y; cin >> op >> x >> y;
        if(op == 1){
            dsu.link(x,y);
        }else{
            int fx = dsu.find(x);
            int fy = dsu.find(y);
            cout << (fx == fy ? "YES" : "NO") << endl; 
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