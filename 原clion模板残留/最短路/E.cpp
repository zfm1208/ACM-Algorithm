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
const int N = 2500 + 5;
int n,m;
vector<pii> a[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<int> dist(N);
void kruskal(){
    fill(dist.begin(),dist.end(),inf);
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().second,d = pq.top().first;
        pq.pop();
        if(dist[u] < d) continue;
        for(auto v:a[u]){
            if(dist[v.first] > dist[u] + v.second){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first],v.first});
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    kruskal();
    if(dist[n] == inf){
        cout << -1 << endl;
    }else{
        cout << dist[n] << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
