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
vector<int> d(N,inf);// 存储到1距离
vector<int> a(N);
int n,m,T;
vector<int> adj[N];
// bfs 求1到其他点的最短距离d[i]
void bfs(){
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
// 思路很容易想到
// 考点是完全背包 ：(每个珠宝有自己的价值和花费的时间  给定一个时间 求出规定时间能获得的最大价值)
// 预处理 点1到其他点的最短时间
// 然后就是完全背包的板子
void solve() {
    cin >> n >> m >> T;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs();
    vector<int> dp(N,0);
    for(int i = 2; i <= n; i++){
        int time = 2 * d[i];
        for(int j = time; j <= T; j++){
            dp[j] = max(dp[j], dp[j - time] + a[i]);
        }
    }
    for(int i = 1; i <= T; i++){
        cout << dp[i] << " \t"[i == T];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}