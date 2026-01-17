#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7, mod2 = 998244353, inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n, a[N], b[N];

bool check(int limit)
{
    int sum = 0; // Petya 自取花费的总时间
    for (int i = 1; i <= n; i++)
        // 如果外卖太慢（超过了限制时间），Petya 必须自己去拿
        if (a[i] > limit)
        {
            sum += b[i];
        }
    // 最后的总自取时间不能超过限制时间
    return sum <= limit;
}

void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int sum_b = 0;
    rep(i, 1, n) cin >> b[i], sum_b += b[i]; 
    int l = 0, r = sum_b;
    int ans = sum_b; 
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) 
        {
            ans = mid;    
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;  
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}