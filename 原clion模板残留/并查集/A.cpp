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
const int N = 2e5 + 5;
pair<int,int> a[N];
int pre[N];
int dp[N];
int find(int x){
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}
void unions(int x,int y){
    int x1 = find(x);
    int y1 = find(y);
    if(x1 != y1){
        pre[x1] = y1;
        a[y1].first += a[x1].first;
        a[y1].second += a[x1].second;
        a[x1].first = a[x1].second = 0;
    }
}
void solve() {
    int n,m,w; cin >> n >> m >> w;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= n; i++){
        pre[i] = i;
    }
    for(int j = 1; j <= m; j++){
        int x,y; cin >> x >> y;
        unions(x,y);
    }
    for(int i = 1; i<= n; i++){
        for(int j = w; j >= a[i].first; j--){
            dp[j] = max(dp[j],dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[w] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
