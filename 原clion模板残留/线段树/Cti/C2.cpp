#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> mp[N];
int ans[N];
void solve() {
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    vis[1] = true;
    ans[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : mp[u]){
            if(!vis[v]){
                ans[v] = ans[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(ans[i] <= d) cnt++;
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}