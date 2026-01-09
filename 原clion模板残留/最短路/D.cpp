//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 500 + 5;
int n,m,st,ed;

vector<vector<int>> mp(N+1,vector<int>(N+1,0));
void dijkstra(){
    vector<int> dist(N, inf);
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,st}); // [x,y] :[换乘次数,车站编号]
    while(!q.empty()){
        int u = q.top().second;
        int d = q.top().first;
        q.pop();

        if(u == ed){
            cout << d << endl;
            return;
        }
        if(dist[u] < d) continue;
        for(int i = 0; i < n; i++){
            if(mp[u][i] != 0 && dist[i] > dist[u] + 1){
                dist[i] = dist[u] + 1;
                q.push({dist[i],i});
            }
        }
    }
    cout << "NO" << endl;
}

void solve() {
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        fill(mp[i].begin(),mp[i].end(),0);
    }
    while(m--){
        int u = -1;
        int v;
        while(cin >> v)
        {
            if(cin.get() == '\n') break;
            if(u != -1) mp[u][v] = 1;
            u = v;
        }
    }
    st = 1, ed = n;
    dijkstra();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
