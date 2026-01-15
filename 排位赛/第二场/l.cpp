#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
#define pii pair<int,int>
#define sort(a) sort(a.begin()+1,a.end())
#define endl '\n'
const int N = 1e6+5;

void fff(){
    int n,m; cin >> n >> m;
    map<int,vector<int>> mp1,mp2;
    int ok = 0;
    vector<vector<int>> adj(n+1);
    rep(i,1,m) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        mp1[v].push_back(u);
        mp2[u].push_back(v);
        if(u == v) {
            /*
                不符合逻辑不合法
            */
            ok = 1;
        } 
        /*
            越界不合法
        */
        if(max(u,v) > n) ok = 2;
        if(min(u,v) < 1) ok = 3;
    }
    // 判断adj有没有环
    vector<int> cn(n+1);
    rep(i,1,n){
        for(auto v: adj[i]){
            cn[v]++;
        }
    }
    queue<int> q;
    rep(i,1,n){
        if(cn[i] == 0) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cnt++;
        for(auto v: adj[u]){
            cn[v]--;
            if(cn[v] == 0) q.push(v);
        }
    }
    //自环不合法
    if(cnt < n) {
        ok = 4;
    }
    if(ok){
        rep(i,1,n) cout << 0;
        cout << endl;
        return;
    }
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        int cnt1 = 0;
        queue<int> q;
        q.push(i);
        vector<int> vis(n+1);
        vis[i] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            for(auto v : mp1[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    cnt1++;
                    q.push(v);
                }
            }
        }

        int cnt2 = 0;
        queue<int> q1;
        q1.push(i);
        fill(vis.begin(), vis.end(), 0);
        vis[i] = 1;
        while(q1.size()){
            int u = q1.front(); q1.pop();
            for(auto v : adj[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    cnt2++;
                    q1.push(v);
                }
            }
        }
        // cout << cnt1 << " " << cnt2 << endl;
        if(cnt1 <= (n/2) && cnt2 <= (n/2)){
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
    }
    rep(i,1,n) cout << ans[i];
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}