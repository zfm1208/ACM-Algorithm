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
struct node{
    int d,k,c;
};
struct node1 {
    int p,q; 
};
void solve(){
    int n,m,r; cin >> n >> m >> r;
    vector<node> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].d >> a[i].k >> a[i].c;
    }
    vector<node1> b(m+1);
    int sum = 0;
    for(int i = 1; i <= m; i++){
        cin >> b[i].p >> b[i].q;
        sum += b[i].q;
    }   
    sort(b.begin()+1,b.end(),[](auto x, auto y){
        return x.p < y.p;
    });
    vector<int> c; //  第 i 次骑行，发生在哪一天
    c.pb(0);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= b[i].q; j++){
            c.push_back(b[i].p);
        }
    }
    // dp 数组一定是单调不降的
    vector<int> dp(sum + 1, inf); // 合法覆盖前 i 次骑行，所需要的最少花费
    dp[0] = 0;
    vector<int> pos(n+1,1);
    for(int i = 1; i <= sum; i++){
        dp[i] = dp[i - 1] + r;
        for(int j = 1; j <= n; j++)
        {
            while(pos[j] <= i && (i - pos[j] + 1 > a[j].k || c[i] - c[pos[j]] >= a[j].d))
                pos[j]++;
            if(pos[j] <= i){
                dp[i] = min(dp[i], dp[pos[j] - 1] + a[j].c);
            }
        }
    }
    cout << dp[sum] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}