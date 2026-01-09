//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define pi acos(-1.0)
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0; // 记录轮次（基数为 2^cnt）
    while (k > (n + 1) / 2) {
        int num = (n + 1) / 2; // 当前轮次中 奇数数量
        k -= num; // 减去当前轮的牌数
        n /= 2;    // 剩余牌的最大值为原最大值/2
        cnt++;     // 轮次增加
    }
    // 此时第 k 个奇数为 (2k-1)，乘以基数 2^cnt
    cout << ((2 * k - 1) << cnt) << endl;
}
/* n == 18 k==15
 * f([1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18],15) * 1
 *
 * // 删了9个数 1 3 5 7 9 11 13 15 17
 * = f([2 4 6 8 10 12 14 16 18],6)
 * = f([1 2 3 4 5 6 7 8 9],6) * 2
 *
 * // 删了5个数 1 3 5 7 9
 * = f([2 4 6 8],1) * 2
 * = f([1 2 3 4],1) * 4
 *
 * ==> 1*4 == 4
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
