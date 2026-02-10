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
// 在序列中找出最多的互不相交的合法区间
// 连续区间 + 和的范围 --> 双指针 / 滑动窗口
// 最大化数量 --> 贪心
void solve(){
    int n,l,r; cin >> n >> l >> r;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int sum = 0;
    int lst = 1;
    for(int now = 1; now <= n; now++){
        sum += a[now];
        while(lst <= now && sum > r){
            sum -= a[lst];
            lst++;
        }
        if(l <= sum && sum <= r){
            ans++;
            sum = 0;
            lst = now+1;
        }
    }
    cout << ans << endl;
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