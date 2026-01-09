//
// Created by zfm25 on 2025/7/17.
//
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
#define yes "YES"
#define no "NO"
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 5005;
int a, b, c1, c2, c3;
vector<int> dist(N);

void dijkstra(int n){
    fill(dist.begin(), dist.end(), inf);
    dist[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(u == b)break;
        if(d > dist[u]){
            continue;
        }
        pii adj[] = {
                {u + 1, c1},
                {u - 1, c2},
                {u * 2, c3},
        };
        for(auto [v,w] : adj){
            if(dist[v] > dist[u] + w && 1 <= v && v <= 2*max(a,b)){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve()
{
    cin >> a >> b >> c1 >> c2 >> c3;
    if (a > b)
    {
        cout << (a - b) * c2 << '\n';
        return;
    }
    dijkstra(a);
    cout << dist[b] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
