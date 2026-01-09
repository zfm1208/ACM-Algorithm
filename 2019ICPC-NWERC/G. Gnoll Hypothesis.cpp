// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// https://qoj.ac/contest/521/problem/2416
void solve() {
    int n,k; cin >> n >> k;
    vector<ld> s(2 * n + 1);
    vector<ld> ans(n+1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[n + i] = s[i];
    }
    for(int i = n + 1; i <= 2 * n; i++){
        ld p = k * 1.0 / n;
        int io = i - n;
        ans[io] = p * s[i];
        for(int j = 1; j <= n - k; j++){
            p = p * (n-k-j+1) / (n-1-j+1);
            ans[io] += p * s[i-j];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << fixed << setprecision(12) << ans[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
    x被选中
    ans[x] = s[x] * (k/n)
    x被选中，x-1未被选中 (还剩n-1个怪物，要选k-1个，也就是要有(n-1)-(k-1) = (n-k)个不被选中)
    ans[x] +=  s[x-1] * (k/n) * (n-k) / (n-1)
    x被选中，x的前2个未被选中
    ans[x] +=  s[x-2] * (k/n) * (n-k)/(n-1) * (n-k-1)/(n-2)。
    ......
*/



/*
n个怪物有k个要被选中，现在考虑x号怪物，在所有方案中它被选中的概率其实就是k/n，
它的答案就加上s[x] * k/n。
接下来还剩n-1个怪物，要选k-1个，也就是要有(n-1)-(k-1) = (n-k)个不被选中，
那x的前一个怪物不被选中的概率其实就是(n-k)/(n-1)，
答案就加上s[x-1] * k/n * (n-k)/(n-1)。依此类推。
也就是说初始概率p为n/k，往前推到x-i个位置，p就乘上(n-k-i+1)/(n-i)，
然后x位置的答案加上s[x-i] * p即可。
*/