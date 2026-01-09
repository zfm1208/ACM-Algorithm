//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2500 + 5;
int n,m,x;
vector<pii> a[N];
vector<int> ans(N);
vector<int> dist(N);
void kruskal(int s){
    fill(dist.begin(),dist.end(),inf);
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
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
    cin >> n >> m >> x;
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        a[u].push_back({v,w});
    }
    int res = -inf;
    for(int i = 1; i <= n; i++){
        kruskal(i);
        ans[i] = dist[x];
        kruskal(x);
        ans[i] += dist[i];
        res = max(res,ans[i]);
    }
    cout << res << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
