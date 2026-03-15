#include<bits/stdc++.h>
using namespace std;
#define int long long
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
struct node{
    int xx,yy,ww;
    bool ok;
};
void solve(){
    int n,m,money,k;
    cin >> n >> m >> money >> k;    
    vector<vector<int>> a(n+1,vector<int>(m+1)),jl(n+1,vector<int>(m+1,-1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<node>> mp(n+1,vector<node>(m+1));
    for(int i = 1; i <= k; i++){
        int x,y,p,q,w;
        cin >> x >> y >> p >> q >> w;
        mp[x][y] = {p,q,w,1};
    }
    priority_queue<array<int,4>> pq;
    pq.push({-0,money,1,1});
    int ans = 1e18;
    while(!pq.empty()){
        auto [ct,ts,cx,cy] = pq.top();
        if(cx == n && cy == m) {
            cout << -ct << '\n';
            return;
        }
        pq.pop();
        if(jl[cx][cy] >= ts) continue;
        jl[cx][cy] = ts;
        for(int i = 0; i < 4; i++){
            int nx = cx + fx[i];
            int ny = cy + fy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(ts <= jl[nx][ny]) continue;
            pq.push({-max(-ct,a[nx][ny]),ts,nx,ny});
        }
        auto [tx,ty,tt,ok]  = mp[cx][cy];
        if(ok == 0) continue;
        if(ts - tt >= 0){
            if(jl[tx][ty] < ts-tt)
            pq.push({-max(a[tx][ty],-ct),ts-tt,tx,ty});
        }
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