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
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int ans = 0;
    int m = min(a1, a2);
    ans += m * 2;
    a1 -= m;
    a2 -= m;
    // 如果 1 还有剩余
    if(a1 > 0){
        ans += (a1 / 3) * 3; // 每凑齐 3 个 '1'，代价是 3
        int rem = a1 % 3;
        if (rem == 2) {
            ans += 1;        // 剩下 2 个 '1'，合并它们需要代价 1*1=1
        }
        // 如果剩下 1 个，代价是 0，不用加
    }
    // 如果 2 还有剩余
    if(a2 > 0){
        ans += (a2 / 3) * 6; // 每凑齐 3 个 '2'，代价是 6
        int rem = a2 % 3;
        if (rem == 2) {
            ans += 4;        // 剩下 2 个 '2'，合并它们需要代价 2*2=4
        }
        // 如果剩下 1 个，代价是 0，不用加
    }
    // a3 对答案贡献为0， 不用管
    cout << ans << "\n";
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