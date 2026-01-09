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
const int inf = 1e18;
const int N = 1e4 + 5;
vector<vector<int>> mp(N,vector<int>(N,-1)); //邻接矩阵mp[][]
void solve() {
    int n,m;
    cin >> n >> m;
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
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
