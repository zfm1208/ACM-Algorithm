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
int ex_gcd(int a, int b, int &x, int& y) {
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ex_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
void solve(){
    int n, m, sum = 0; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        sum = (sum + x) % m;
    }
    // T = (sum + A * s + B * d) % m 值最小
    int A = n, B = n * (n + 1) / 2;
    int g = __gcd(A, B);
    // T = sum + x * g + y * m
    int gg = __gcd(g, m);
    // T = sum + k * gg 最小值
    int ans = sum % gg;
    cout << ans << endl;
    int t = - (sum / gg);
    int x,y;
    ex_gcd(g, m, x, y);
    // g * x + m * y == gcd(g, m) == gg
    // g * x + m * y == t * gg
    x *= t;
    x = (x % m + m) % m;
    int s,d;
    ex_gcd(A, B, s, d);
    // A * s + B * y == gcd(A, B) == g
    // A * s + B * y == x * g
    s *= x;
    d *= x;
    s = (s % m + m) % m;
    d = (d % m + m) % m;
    cout << s << " " << d << endl;
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