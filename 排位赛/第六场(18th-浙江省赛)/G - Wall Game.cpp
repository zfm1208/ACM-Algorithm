#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 2e5+10, mod = 1e9+7, base = 131;
#define pb push_back
const int dx[] = {1,0,0,-1,1,-1};
const int dy[] = {0,1,-1,0,-1,1};
struct DSU{
    vector<int> fa;
    vector<int> zc;
    DSU(int n){
        fa.resize(n+1);
        zc.resize(n+1);
        for(int i = 1; i <= n; i++){
            fa[i] = i;
        }
    }
    int find(int x){
        if(fa[x] != x){
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    void link(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
            zc[fy] += zc[fx];
        }
    }
};

void solve(){
    int n; cin >> n;
    DSU dsu(n);
    map<pii,int> mp;
    int num = 1;
    for(int k = 1; k <= n; k++){
        int op,x,y; cin >> op >> x >> y;
        if(op == 1){
            mp[{x,y}] = num;
            dsu.zc[mp[{x,y}]] = 6;
            for(int i = 0; i < 6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(mp[{nx,ny}]){
                    dsu.zc[dsu.find(mp[{nx,ny}])] -= 1;
                    dsu.zc[mp[{x,y}]] -= 1;
                    dsu.link(mp[{nx,ny}],mp[{x,y}]);
                }
            }
            num++;
        }else{
            cout << dsu.zc[dsu.find(mp[{x,y}])] << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}