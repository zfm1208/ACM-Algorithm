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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
struct DSU {
    vector<int> fa;
    vector<int> siz;
    int sum;

    DSU(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        sum = 0;
        for(int i = 0; i <= n; i++){
            fa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int x){
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    int calc(int n){
        return n * (n+1) / 2;
    }

    void unint(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            sum -= calc(siz[fx]);
            sum -= calc(siz[fy]);

            fa[fx] = fy;
            siz[fy] += siz[fx];

            sum += calc(siz[fy]);
        }
    }
};

/*
    我们发现对于k，若一个点i, abs(p[i] - p[i+1]) < k， 那么这个点会讲数组分成两部分，也就是分块
    对于不同的块，贡献很好算，若一个块的长度为 n ，那么我们要在这个块中找长度至少为2的子数组，
    也就是，找两个不同的点的个数,贡献为 n*(n+1)/2 

    现在要求出每个k的答案，我们可以从大到小枚举k
    当我们从k -> k-1时，我们只需要把 abs(p[i] - p[i+1]) == k-1 的点连起来即可
    这样我们就能维护出每个k的答案

    原因：当我们从大到小枚举
    假设当前k，我们已经把所有 abs(p[i] - p[i+1]) >= k 的点连起来了
    那么当我们枚举到 k-1 时，我们只需要把 abs(p[i] - p[i+1]) == k-1 的点连起来
    这样我们就能保证每次枚举k时，所有 abs(p[i] - p[i+1]) >= k 的点都已经连起来了
    
*/
void solve(){
    int n; cin >> n;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    vector<vector<int>> g(n+1);
    for(int i = 1; i < n; i++){
        g[abs(p[i] - p[i+1])].pb(i);
    }
    DSU dsu(n);
    vector<int> ans(n+1);
    // 枚举k 从 n-1 -> 1
    for(int k = n-1; k >= 1; k--){
        for(auto i : g[k]){ 
            dsu.unint(i,i+1);
        }
        ans[k] = dsu.sum;
    }
    rep(i,1,n-1) cout << ans[i] << " \n"[i == n-1];

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