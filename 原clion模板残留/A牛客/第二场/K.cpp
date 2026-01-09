//https://ac.nowcoder.com/acm/contest/95334/K
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;

int n,m,ans = inf;
char a[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool vis[501][501];
int bfs(int x,int y){
    queue<pii> op;
    vis[x][y] = 1;
    op.push({x,y});
    set<pii> st;
    while(!op.empty()){
        int x1 = op.front().first;
        int y1 = op.front().second;
        op.pop();
        for(int i = 0; i < 4; i++){
            int xx = x1 + dx[i];
            int yy = y1 + dy[i];
            if(xx >= 1 && yy >= 1 && xx <= n && yy <= m){
                if(a[xx][yy] == '0') st.insert({xx,yy});
                if(!vis[xx][yy] && a[xx][yy] == '1'){
                    vis[xx][yy] = 1;
                    op.push({xx,yy});
                }
            }
        }
    }
    return st.size();
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '1' && !vis[i][j]){
                int cnt = bfs(i,j);
                ans = min(ans,cnt);
            }
        }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
