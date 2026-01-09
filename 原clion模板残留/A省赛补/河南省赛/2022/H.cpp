//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
bool vis[5][N];
char g[5][N];
int n,sx,sy;
// 1下 2上 3左 4 右
int dfs(int x,int y,int d){
    if(x == 3 && y == sy) return true;
    if(vis[x][y]) return false;
    if(x < 1 || x > 2 || y < 1 || y > n) return false;
    vis[x][y] = 1;
    bool ok;
    if(g[x][y] == 'I'){
        if(d == 1) ok = dfs(x + 1, y, 1);
        else if(d == 3) ok = dfs(x, y - 1, 3);
        else if(d == 4) ok = dfs(x, y + 1, 4);
    }
    else{
        if(d == 1 || d == 2)
            ok = (dfs(x, y + 1, 4) || dfs(x, y - 1, 3));
        else if(d == 3 || d == 4)
            ok = (dfs(x - 1, y, 2) || dfs(x + 1, y, 1));
    }
    //记得回溯！！！
    vis[x][y] = 0;
    return ok;
}
void solve() {
    cin >> n >> sx >> sy;
    for(int i = 1; i <= 2; i++){
        string s; cin >> s;
        s = " " + s;
        for(int j = 1; j <= n; j++){
            vis[i][j] = false;
            g[i][j] = s[j];
        }
    }
    if(dfs(1,sx,1)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}