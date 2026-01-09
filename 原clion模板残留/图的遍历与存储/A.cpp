#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 1e5 + 10;
using namespace std;
vector<int> mp[N];
bool vis[N];
void dfs(int x){
    for(auto i : mp[x]){
        if(!vis[i]){
            cout << i << ' ';
            vis[i] = 1;
            dfs(i);
        }
    }
}
queue<int> q;
void bfs(int x){
    vis[x] = 1;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto i : mp[t]){
            if(!vis[i]){
                vis[i] = 1;
                cout << i << ' ';
                q.push(i);
            }
        }
    }
}
void solve()
{
    int n,m; cin >> n >> m;
    int u,v;
    for(int i = 1; i <= m; i ++){
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for(int i = 1; i <= n; i ++){
        sort(mp[i].begin(),mp[i].end());
    }
    vis[1]=1;

    cout << 1 << ' ';dfs(1);
    cout << endl;
    memset(vis,0,sizeof(vis));
    cout << 1 << ' ';
    bfs(1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

