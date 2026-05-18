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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char ch[] = {'N', 'S', 'W', 'E'}; 

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(m);
    int sx = -1, sy = -1;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    vector<vector<int>> dist(m, vector<int>(n, inf));
    queue<pii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] != '#') {
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<pii> ans; 
    ans.pb({sx, sy});
    vector<vector<int>> vis(m, vector<int>(n, -1));
    for(int step = 1; step <= len; step++){
        char f = s[step]; 
        vector<pii> nxt;      
        for(auto [x, y] : ans){
            for(int i = 0; i < 4; i++){
                if (ch[i] == f) continue;
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] != '#'){
                    if(dist[nx][ny] == step && vis[nx][ny] < step){
                        vis[nx][ny] = step;
                        nxt.pb({nx, ny});
                    }
                }
            }
        }
        ans = nxt;
    }
    for(auto [x, y] : ans){
        a[x][y] = '!'; 
    }
    for(int i = 0; i < m; i++){
        cout << a[i] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--)
        solve();
    return 0;
}