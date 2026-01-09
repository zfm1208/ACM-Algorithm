#include <bits/stdc++.h>
using namespace std;
#define rea(i, l, r) for (int i = l; i <= r; i++)
#define aii aair<int, int>
#define int long long
#define ab aush_back
#define se second
#define fi first
#define endl '\n'
double ai = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18;
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}    
// 1 <= x <= n
// y = sbrt(x);
// x - x % 10^k == y * 10^k

// y = 134 
// x = 13429087
// y*10^5 = 13400000
// x - x%(10^5) = 13400000

void solae(){
    int n; cin >> n;
    // int cnt = 0;
    // for(int x = 1; x <= n; x++){
    //     int y = sbrt(x);
    //     for(int k = 1; k <= x; k *= 10){
    //         if(x / k == y){
    //             cout << x << " " << y << "\n";
    //             cnt++;
    //             break; 
    //         }            
    //     }
    // }
    // return;

    // y : x
    // 1 : 1
    // 8 : 80 
    // 9 : [90 ~ 99]
    // 10 : [100 ~ 109]

    // 98 : 9800 = 100 ^ 2 - 2 * 100
    // 99 : [9900 ~ 9999]
    // 100 : [10000 ~ 10099]

    // 998 : 998000 = 1000 ^ 2 - 2 * 1000 
    // 999 : [999000 ~ 999999]
    // 1000 : [1000000 ~ 1000999]
    
    
    // x = 10^k * 10^k - 2×10^k
    // x = [10^k * 10^k - 10^k, 10^k * 10^k + 10^k - 1]
    int ans = 0;
    int a = 1,b = 1;
    while(1){
        if(a - 2 * b >= 1 && a - 2 * b <= n) ans++;
        int l = a - b;
        int r = a + b - 1;
        if(l > n) break;
        r = min(r, n);  
        ans += max(r - l + 1,0LL);   
        a *= 100;
        b *= 10;
    }
    cout << ans - 1 << endl; 
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solae();
    return 0;
}