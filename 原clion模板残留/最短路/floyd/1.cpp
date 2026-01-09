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
int dist[N][N];
//适用于无负权回路的稠密图， 运行一次即可求得任意两点间的最短路
void solve() {
    // 时间复杂度O(n^3)，空间复杂度O(n^2)
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= n; y++){
                if(dist[x][y] > dist[x][i] + dist[i][y]){
                    dist[x][y] = dist[x][i] + dist[i][y];
                    dist[y][x] = dist[x][y];
                }
            }
        }
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
