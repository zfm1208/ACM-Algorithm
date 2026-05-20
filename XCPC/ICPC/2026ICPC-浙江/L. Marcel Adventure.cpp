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

void solve(){
    int n, m; cin >> n >> m;
    int sx,sy,sz,tx,ty,tz;
    cin >> sx >> sy >> sz >> tx >> ty >> tz;
    vector<int> rx(n+1), ry(n+1), rz(n+1);
    map<array<int,3>, int> zi;
    map<pii, vector<int> > mp;
    for(int i = 1; i <= n; i++){
        cin >> rx[i] >> ry[i] >> rz[i];
        zi[{rx[i], ry[i], rz[i]}]++;
        mp[{rx[i], ry[i]}].push_back(rz[i]);
    }
    for(auto &[_, arr]: mp){
        sort(arr.begin(), arr.end());
    }
    vector<int> a(m+1), b(m+1), c(m+1);
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    map<array<int,3>, int> vis;
    queue<array<int,4>> q;
    q.push({0,sx,sy,sz});
    vis[{sx,sy,sz}] = 1;
    while(!q.empty()){
        auto[step, x, y, z] = q.front();
        q.pop();
        if(x == tx && y == ty && z == tz){
            cout << step << endl;
            return;
        }
        for(int i = 1; i <= m; i++){
            int nx = x + a[i];
            int ny = y + b[i];
            int nz = z + c[i];
            if(zi.count({nx, ny, nz})) continue;
            if(!mp.count({nx, ny})) continue;
            auto it = lower_bound(mp[{nx,ny}].begin(), mp[{nx,ny}].end(), nz);
            if(it != mp[{nx,ny}].begin() && *(it - 1) < nz) {
                int obs_z = *(it - 1);
                if(!vis.count({nx, ny, *(it - 1) + 1})) {
                    vis[{nx, ny, *(it - 1) + 1}] = 1; 
                    q.push({step + 1, nx, ny, *(it - 1) + 1});
                }
            }
        }
    }
    cout << -1 << endl;
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