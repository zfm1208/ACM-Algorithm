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
// https://codeforces.com/problemset/problem/1901/C

/*
    * 题意： 
    给定一个长度为 n 的序列 {} a, 每次操作你需要选择一个整数 x 并将所有
    a[i] -> (a[i] + x ) / 2,求至少多少次操作后能将所有 a[i] 变相同
    若最少次数小于等于 n，输出操作次数和每次操作所选择的 x。否则仅输出操作次数。

    * 分析:
    既然是整体 操作, 可以知道，每次操作后，数字的相对大小是不会发生变化的
    那么就启发我们不用同时维护原序列中的所有值，
    只需要维护序列中的最大值和最小值。当这两个值相等时，就代表序列中所有的数都相同了。
    那么我们所做的每一步都是要缩小 mx 和 mn 之间的差距而不是增大它们之间的差距。
    那可以选什么x值呢？  
    无论我们选择什么样的 x，操作本质上是在做“除法”
    由于是下取整，两个数的差距在操作后会不断缩小
    ! 我们不难发现，其相对大小关系只与每次所选的 x 奇偶性有关，而与 x 的具体大小无关

    你选2 ,4,6,8 都不会影响他们的相对大小关系

    那么可选的x 可以从0 , 1 中选

*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int mx = -inf, mn = inf;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mx == mn) {
        cout << 0 << endl;
        return;
    }
    vector<int> ans;
    while(mn != mx){
        int x = 0;
        if(mn & 1 && (mx % 2 == 0)) x = 1;
        else if(mx & 1 && (mn % 2 == 0)) x = 0;
        else x = 0;
        ans.pb(x);
        mn = (mn + x) / 2;
        mx = (mx + x) / 2;
    }
    cout << ans.size() << endl;
    if(ans.size() <= n && ans.size() > 0){
        for(int x: ans) cout << x << " ";
        cout << endl;
    }
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