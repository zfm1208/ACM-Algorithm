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
// 0 (0~c) c+1
// 1 (1~c) c
// 2 (2~c) c-1
// .. 
// c (c~c) 1

/*
    容斥原理
    易知 y >= x
    <1> : 要减去x + y == s的情况
        y = s - x; x <= y   :   x <= s / 2
        (0 <= x <= s/2)
        sum += (s/2 + 1)

    <2> : 要减去y - x == s的情况
        y = x + s; y <= c   :   x <= c - s
        sum += (c-s+1)

    <3> : 减去重复的情况
        x + y = s1 && y - x = s2 

        * x = (s1 - s2) / 2
        * y = (s1 + s2) / 2
    
    x,y 必须奇偶性相同 x >= 0 
    !:  a >= b && (a - b) % 2 == 0
    记奇数个数: ji ,偶数个数: ou
    sum -= ji* (ji + 1) / 2 + ou * (ou+1) / 2
*/
void solve(){
    int n,c; cin >> n >> c;
    vector<int> a(n+1);
    int ji = 0, ou = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] & 1 ? ji++: ou++;
    }
    int ans = (c+2) * (c+1) / 2;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (a[i] / 2 + 1);
        sum += (c - a[i] + 1);
    }
    sum -= (ji+1) * ji / 2 + (ou+1) * ou / 2;
    cout << ans - sum << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}