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
// 每个煎饼有两面，n 个煎饼总共有 2n 面需要煎。
// 锅每次最多能同时煎 k 面。
// 为了让总时间最短，我们要尽量保证锅在每一小时内都是“满载”的（尽量不要空着位置）。
void solve(){
    int n,k;
    cin >> n >> k;
    if(n <= k) // 锅足够大，能一次性放下所有煎饼
    {
        cout << 2;
    }
    else 
    {
        if(n % k==0) // 煎饼数量刚好是锅容量的整数倍
        {
            cout << n / k * 2;
        }
        else 
        {
            cout << (n * 2 + k - 1) / k;
        }
    }
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