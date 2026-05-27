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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
struct edge {
    int u, v;
    int w;
    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n + 1);
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int i){
        if (fa[i] == i)  return i;
        return fa[i] = find(fa[i]); 
    }
    void unite(int i, int j) {
        int rx = find(i);
        int ry = find(j);
        if (rx != ry) {
            fa[rx] = ry;
        }
    }
};
void solve(){
    int n, m;cin >> n >> m;
    vector<edge> e(m);
    for(int i = 0; i < m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e.begin(), e.end());
    DSU dsu(n);
    vii e1,e2;
    for(int i = 0; i < m; i++){
        if(dsu.find(e[i].u) != dsu.find(e[i].v)){
            dsu.unite(e[i].u, e[i].v);
            e1.push_back(e[i].w);
        } else {
            e2.push_back(e[i].w);
        }
    }

    double mn = inf; 
    for(int k = n - 1; k <= m; k++){
        int cnt = k - (n - 1);
        vii cun;
        int p1 = 0, p2 = 0;
        while (p1 < e1.size() && p2 < cnt) {
            if (e1[p1] < e2[p2]) {
                cun.push_back(e1[p1++]);
            } else {
                cun.push_back(e2[p2++]);
            }
        }
        while (p1 < e1.size()) cun.push_back(e1[p1++]);
        while (p2 < cnt) cun.push_back(e2[p2++]);
        double cur = 0;
        for(int i = 0; i < k; i++){
            cur += (double)cun[i] / (i + 1);
        }
        mn = min(mn, cur);
    }
    cout << (int)round(mn) << "\n";
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