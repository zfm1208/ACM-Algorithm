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
const int N = 1e5+6, mod = 1e9+7, inf = 1e18 + 5;
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
            if(fy > fx) swap(fx,fy);
            fa[fx] = fy;
        }
    }
};
struct node {
    int id; 
    int people;
    double fc; // 房产套数
    double mj; // 房产面积
};
void solve(){
    int n; cin >> n;
    DSU dsu(N);
    vector<int> vis(N);
    vector<int> afc(N),amj(N);
    for(int i = 1; i <= n; i++){
        int id,bb,mm;
        cin >> id >> bb >> mm;
        vis[id] = 1;
        if(bb != -1){
            dsu.link(bb,id);
            vis[bb] = 1;
        }
        if(mm != -1){
            dsu.link(mm,id);
            vis[mm] = 1;
        }
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int hz; cin >> hz;
            if(hz != -1){
                dsu.link(hz,id);
                vis[hz] = 1;
            }
        }
        int fc,mj; cin >> fc >> mj;
        afc[id] = fc;
        amj[id] = mj;
    }
    vector<int> ren(N);
    for(int i = 0; i < N; i++){
        if(vis[i]){
            int root = dsu.find(i);
            ren[root] ++;
            if(i == root) continue;
            afc[root] += afc[i];
            amj[root] += amj[i];
        }
    }
    vector<node> ans;
    for(int i = 0; i < N; i++){
        if(vis[i] && dsu.find(i) == i){
            double av1 = 1.0 * afc[i] / ren[i];
            double av2 = 1.0 * amj[i] / ren[i];
            ans.pb({i, ren[i], av1, av2});
        }
    }
    sort(ans.begin(),ans.end(),[](auto &x, auto &y){
        if((abs(x.mj - y.mj) > 1e-5)) return x.mj > y.mj;
        return x.id < y.id;
    });
    cout << ans.size() << endl;
    for(auto &tp: ans){
        cout << setfill('0') << setw(4) << tp.id << " " << tp.people << " " << fixed << setprecision(3) << tp.fc << " " << setprecision(3) << tp.mj << endl;
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