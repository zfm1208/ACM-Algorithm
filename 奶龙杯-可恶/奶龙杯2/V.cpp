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
const int N = 1e3+10, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
int n;
int e1[N][N];
int e2[N][N];
int dist[N][N];
int dx[] = {0,0,1, -1};
int dy[] = {1, -1, 0, 0};
int dijkstra(int e[N][N],int sx,int sy, int ex, int ey){
    rep(i,1,n) rep(j,1,n) dist[i][j] = inf;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    dist[sx][sy] = 0;
    pq.push({0,{sx,sy}});
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        int d = tp.fi;
        auto [x,y] = tp.se;
        if(d > dist[x][y]) continue;
        if(x == ex && y == ey) return d;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(dist[x][y] + e[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + e[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == 'R') e1[i][j] = 0;
            else e1[i][j] = 1;
            if(c == 'B') e2[i][j] = 0;
            else e2[i][j] = 1;
        }
    }
    int ans1 = dijkstra(e1, 1, 1, n, n);
    int ans2 = dijkstra(e2, 1, n, n, 1);
    cout << ans1 + ans2 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}