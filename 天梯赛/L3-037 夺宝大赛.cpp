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
const int fx[] = {1,-1,0,0};
const int fy[] = {0,0,1,-1};
struct node {
    int x, y, time;
    bool operator<(const node& tp)  const {
        return time > tp.time;
    } ;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    int ex,ey;
    rep(i,1,n)rep(j,1,m){
        cin >> a[i][j];
        if(a[i][j] == 2){
            ex = i, ey = j;
        }
    }
    int k; cin >> k;
    vector<array<int,3>> arr(k+1);
    for(int i = 1; i <= k; i++){
        int x,y; cin >> x >> y;
        arr[i] = {x,y,i};
    }
    vector<vector<int>> vis(n+1,vector<int>(m+1));
    priority_queue<node> pq;
    pq.push({ex,ey,0});
    vis[ex][ey] = 1;
    vector<vector<int>> ans(n+1,vector<int>(m+1,inf));
    ans[ex][ey] = 0;
    while(pq.size()){
        auto [x,y,cur] = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + fx[i];
            int ny = y + fy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(vis[nx][ny] == 1) continue;
            if(a[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            ans[nx][ny] = cur+1;
            pq.push({nx,ny,cur+1});
        }
    }
    map<int,vector<int>> mp;
    for(int i = 1; i <= k; i++){
        auto&[x,y,id] = arr[i];
        mp[ans[y][x]].pb(i);
    }
    for(auto &[x,ar]: mp){
        if(x != inf) if(ar.size() == 1){
            cout << ar[0] << " " << x;
            return;
        }
    }
    cout << "No winner.";
    
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