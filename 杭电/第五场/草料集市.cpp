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

void solve(){
    // dp过了，但是严格意义上会超时
    int n,k; cin >> n >> k;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i] / 2;
    }
    // dp[i] : 前i天最小价格，并且第i天要原价买
    vector<int> dp(n+1, inf);
    dp[1] = a[1] / 2;
    for(int i = 2; i <= n; i++){
        int x = inf;
        for(int j = i-1; j >= max(1LL, i-k-1); j--){
            x = min(x, dp[j]);
        }
        dp[i] = x + a[i] / 2;
    }
    int ans = inf;
    for(int i = max(1LL, n-k); i <= n; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans + pre[n] << endl;
}

// 优化 用优先队列去维护区间最小值
void solve1(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i] / 2;
    }
    // 截至到i位置，且i全价买时的最小价格
    vector<int> dp(n+1, inf);
    dp[1] = a[1] / 2;
    deque<int> dq;
    dq.push_back(1);
    for(int i = 2; i <= n; i++){
        while(!dq.empty() && dq.front() < i - k - 1) dq.pop_front();
        if(!dq.empty()) dp[i] = dp[dq.front()] + a[i] / 2;
        while(!dq.empty() && dp[dq.back()] >= dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int ans = inf;
    for(int i = max(1LL, n-k); i <= n; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans + sum << endl;
}
// 优化2 ，用multiset去维护一个区间最小值
// 我们每次需要删掉最左边的值，还需要添加当前值，还要能查询区间最小值
void solve3() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i] / 2;
    }
    vector<int> dp(n+1,inf);
    dp[1] = a[1] / 2;
    multiset<int> st;
    for(int i = 2; i <= n; i++){
        st.insert(dp[i-1]);
        if(i-k-2 >= 1) st.erase(st.find(dp[i-k-2]));
        dp[i] = *st.begin() + a[i] / 2;
    }
    int ans = inf;
        for(int i = max(1LL, n-k); i <= n; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans + sum << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve3();
    return 0;
}