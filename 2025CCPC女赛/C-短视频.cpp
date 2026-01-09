// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
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

void solve() {
    int n, T;
    cin >> n >> T;
    int sum = 0;
    while(n--){
        int t, k;
        cin >> t >> k;
        if(sum + t <= T){
            sum += t;
        }else{
            if(sum + t - T <= k){
                sum += t;
            }else{
                sum = max(sum, k + T);
                sum++;
            }
        }
    }
    cout << sum << '\n';
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