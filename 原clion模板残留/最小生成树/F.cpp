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
const int N = 550 * 550;
int pre[N];
struct node{
    int u;
    int v;
    double w;
}a[N];

int find(int x){
    if(x == pre[x]) return x;
    return pre[x] = find(pre[x]);
}
double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void solve() {
    int n,k; cin >> n >> k;
    if(k >= n){
        cout << 0.00 << endl;
        return;
    }
    if(k<2) k=max(k,1ll);
    pair<double,double> mp[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> mp[i].first >> mp[i].second;
    }
    // n个点 共 n*(n-1)/2条边
    // i
    //j 1 2 3 4 5
    //   2 3 4 5
    //     3 4 5
    //       4 5
    //         5
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cnt++;
            double dis = dist(mp[i].first,mp[i].second,mp[j].first,mp[j].second);
            a[cnt] = {i,j,dis};
        }
    }
    sort(a + 1, a + cnt + 1,[](node x,node y){
        return x.w < y.w;
    });
    for(int i = 1; i <= n; i++) pre[i] = i;
    int count = 0;
    for(int i = 1; i <= cnt; i++){
        int u = a[i].u;
        int v = a[i].v;
        double w = a[i].w;
        u = find(u),v = find(v);
        if(u != v){
            pre[u] = v;
            count++;
            if(count == n - k){
                printf("%.2lf\n",w);
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
