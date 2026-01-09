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
const int N = 200 + 5;
int g[N][N]; //g[i][j]表示i到j的最短距离
int h[N][N]; //h[i][j] 从i到j的花费
void solve() {
    memset(h,0x3f3f3f3f,sizeof(h));
    int n,m;cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int s,e;cin >> s >> e;
        cin >> g[s][e];
        g[e][s]=g[s][e];
        h[s][e]=h[e][s]=0;
    }
    int k;cin >> k;
    for(int i=1;i<=k;i++)
    {
        int s,e;cin >> s >> e;
        h[s][e]=h[e][s]=g[s][e];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
            }
        }
    }
    int st,ed;cin >> st >> ed;
    cout << h[st][ed];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
