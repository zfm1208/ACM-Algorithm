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

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> rdu(n+1);
    for(int i = 1;i <= m; i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        rdu[v]++;
    }
    if(m != n-1){
        cout << "NO" << endl;
        return;
    }
    int cnt = 0;
    int st = -1;
    for(int i = 1; i <= n; i++){
        if(rdu[i] == 0){
            st = i;
            cnt++;
        }
    }
    if(cnt != 1){
        cout << "NO" << endl;
        return;        
    }
    int cur = st;
    cnt = 0;
    while(1){
        cnt++;
        if(adj[cur].size() > 1){
            cout << "NO" << endl;
            return;
        }
        if(adj[cur].size() == 1){
            cur =  adj[cur][0];
        }else{
            break;
        }
    }
    if(cnt == n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
        return;        
    }
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