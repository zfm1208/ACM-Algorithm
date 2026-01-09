//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double PI = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int q; cin >> q;
    while(q--){
        int n,m; cin >> n >> m;
        if(m%n==0){
            cout << 0 << endl;
        }else if(n > m){
            cout << n-m << endl;
        }else{// n < m
//            int nn = n;
//            int s1 = m/n;
//            int s2 = n*(s1+1);
//            int mn = abs(m-s2);
////            cout << mn << endl;
//            int cnt = 0;
//            for(int i = nn-1; i > 0; i--){
//                cnt++;
//                s1 = m/i;
//                s2 = i*(s1+1);
//                mn = min(mn,abs(m-s2)+cnt);
//            }
//            cout << mn << endl;
//          超时 优化算法  减少重复枚举
//          分块除法
//          ans = ceil[m/(n-x)] * (n-x) - m + x
//          设 l == n-x
//          ceil[m/l] * l - m + n - l
//          ceil[m/l] * l - l - m + n
//          因为 ceil[x/k]  == >   (x+k-1) / k
//          所以 ceil[m/l] * l - l == ceil[(m-1)/l] * l
//          ans = ceil[(m-1)/l] * l - m + n
            int ans = 1e9;
            for(int l = 1,r; l <= n; l = r + 1){
                int d = (m-1) / l;
                if(( m-1) / d == 0) r = n;
                else r = (m - 1) / d;
                ans = min(ans,( m - 1) / l * l - m + n);
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}