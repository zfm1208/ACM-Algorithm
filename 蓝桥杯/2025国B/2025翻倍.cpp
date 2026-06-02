#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// a * 2^x(mid)  与  b * 2^y 的大小
int cmp(int a, int x, int b, int y){
    if(x == y){
        if(a == b) return 0;
        return a < b ? -1 : 1;
    }
    if(x > y){
        int d = x - y;
        if(d >= 32) return 1;
        __int128 left = (__int128)a << d;
        if(left == b) return 0;
        return left < b ? -1 : 1;
    }
    int d = y - x;
    if(d >= 32) return -1;
    __int128 right = (__int128)b << d;
    if(a == right) return 0;
    return a < right ? -1 : 1;
}
/*
1. 贪心：从左往右，让当前数追上前一个最终值。
2. 朴素模拟：while 当前值 < 前一个值，就乘 2。
3. 发现问题：最终值可能爆 long long。
4. 转换表示：不存真实值，存成 原始值 * 2^翻倍次数。
5. 新问题：要比较 a * 2^x 和 b * 2^y。
6. 数学消幂：比较指数差，而不是直接算大数。
7. 题目范围 Ai < 2^32，所以指数差 >= 32 时可以直接判断大小。
8. 指数差 < 32 时，用 __int128 安全计算。
9. 当前翻倍次数满足单调性，所以用二分找最小次数。
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int ans = 0;
    int last = a[1], lastCnt = 0;
    for(int i = 2; i <= n; i++){
        int l = 0, r = lastCnt + 32;
        int res = r;
        while(l <= r){
            int mid = (l + r) / 2;
            if(cmp(a[i], mid, last, lastCnt) >= 0){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        ans += res;
        last = a[i];
        lastCnt = res;
    }
    cout << ans << endl;
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
