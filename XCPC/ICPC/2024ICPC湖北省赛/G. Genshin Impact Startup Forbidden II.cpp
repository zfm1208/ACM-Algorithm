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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int e[30][30];
/*
    e[x][y]  0: 空, 1: 黑, 2: 白
*/    
void solve(){
    int m; cin >> m;
    
    auto check = [&] (int sx, int sy, int tar, int bj[30][30] ) -> int {
        if(e[sx][sy] != tar) return 0;
        bj[sx][sy] = 1;
        int vis[30][30] = {0};
        queue<pii> q;
        vector<pii> cun;
        int cnt = 0;
        q.push({sx, sy});
        vis[sx][sy] = 1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            cun.push_back({x, y});
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > 19 || ny < 1 || ny > 19) continue; 
                if(e[nx][ny] == 0){
                    if(!vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        cnt++;
                    }   
                }else if(e[nx][ny] == tar){
                    if(!vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        bj[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }        
        }
        if(cnt == 0){
            for(auto [x,y] : cun){
                e[x][y] =0;
            }
            return cun.size();
        }
        return 0;
    };

    for(int i = 1; i <= m; i++)
    {
        int x,y; 
        cin >> x >> y;
        int cor = (i & 1) ? 1 : 2;
        e[x][y] = cor;
        int ansb = 0, answ = 0;
        int vis[30][30] = {0};
        for(int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || nx > 19 || ny < 1 || ny > 19) continue;
            if(e[nx][ny] == (3 - cor) && vis[nx][ny] == 0)
            {
                int tot = check(nx, ny, (3 - cor), vis);
                if(cor == 1) answ += tot;
                else ansb += tot;
            }
        }
        int vis2[30][30] = {0};
        int tot = check(x, y, cor, vis2);
        if(cor == 1) ansb += tot;
        else answ += tot;  

        cout << ansb << " " << answ << endl;      
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