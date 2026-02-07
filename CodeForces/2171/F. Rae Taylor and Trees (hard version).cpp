#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
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
/*
    构造一个树，使得每条边的u,v ,有 u < v && p[u] < p[v];
    p[i] : 是i在数组中的位置
    deque  //队列来维护当前的节点序列
    队列里的元素是单调递减的：[大数, 中数, 小数]
    q.front() 是当前队列里最大的数
    q.back() 是当前队列里最小的数
*/
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<pii> ans;
    deque<int> q;
    q.push_front(1);
    for(int i = 2; i <= n; i++){
        while(q.size() > 1 && a[i] > a[q.front()]){
            ans.pb({q.front(),i});
            q.pop_front();
        }
        // 现在的 q.front() 要么比 a[i] 大，要么队列只剩一个元素。
        if(a[i] > a[q.back()]){
            ans.pb({q.back(),i});
        }else if(a[i] < a[q.back()]){
            q.push_back(i);
        }
    }
    if(ans.size() != n - 1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for (auto [x,y] : ans) cout << a[x] << " " << a[y] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}