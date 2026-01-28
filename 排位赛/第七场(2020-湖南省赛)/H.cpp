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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    让求两个矩阵合并的面积 = 两个矩阵的面积和-重叠部分的面积
    其中一个矩阵是固定的
    另一个是有范围的

*/
int sum_n(int n){
    n %= mod;
    return n * (n + 1) % mod * 500000004 % mod; 
}
void solve(){
    int a,b,x1,x2,y1,y2;
    while(cin >> a >> b >> x1 >> x2 >> y1 >> y2)
    {
        int area_A = (x2-x1) % mod * ((y2-y1) % mod) % mod;
        int ans1 = a % mod * b % mod * area_A % mod;
        int sum_a = sum_n(a);
        int sum_b = sum_n(b);
        int ans2 = sum_a * sum_b % mod;
        auto get = [&] (int p, int l, int r) -> int {
            if(p <= l) return 0;
            int sum = 0;
            int op = min(p,r) - l;
            sum = (sum + sum_n(op)) % mod;
            if(p > r){
                sum = (sum + ((p - r) % mod) * ((r - l) % mod) % mod) % mod;
            }
            return sum;
        };
        int ans3 = get(a,x1,x2) % mod * get(b,y1,y2) % mod;
        int ans = ((ans1 + ans2) % mod - ans3 + mod) % mod;
        cout << ans << endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}