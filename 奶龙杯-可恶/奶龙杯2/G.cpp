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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solae(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int ans = 0;
    vector<int> a(n+1,0);
    for(int i = 1; i <= n; i++){
        if(s[i] == s[1]) a[i] = 1;
        else a[i] = -1;
    }
    int sum = 0;
    for(int i = 2;i <= n; i++){
        int tp = sum + a[i];
        if((sum + a[1] > 0) && tp <= 0) ans++;
        else if((sum + a[1] == 0) && tp != 0) ans++;
        else if((sum + a[1] < 0) && tp >= 0) ans++;
        sum += a[i];
    } 
    cout << ans + 1 << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solae();
    return 0;
}