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
    int n,m,k;
    cin >> n >> m >> k;
    DSU dsu(n);
    map<pii,int> mp;
    for(int i = 1; i <= m; i++){
        int x,y,op; 
        cin >> x >> y >> op;
        if(op == 1){
            dsu.link(x,y);
        }else if(op == -1){
            if(x > y) swap(x,y);
            mp[{x,y}] = 1;
        }
    }
    while(k--){
        int x,y; cin >> x >> y;
        if(x > y) swap(x,y);
        if(dsu.find(x) == dsu.find(y)){
            if(mp.count({x,y})){
                cout << "OK but..." << endl;
            }else{
                cout << "No problem" << endl;
            }
        }else{
            if(mp.count({x,y})){
                cout << "No way" << endl;
            }else{
                cout << "OK" << endl;
            }
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