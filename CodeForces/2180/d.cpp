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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    /*
        由题意我们可知,符合情况的只有相邻的两个点(a[i], a[i-1])
        dist = a[i] - a[i-1] = r_i + r_(i-1);
        如果前一个点的r确定了，那么r+1也确定了，而我们知道前一个点的r是一个区间[L,R];
        我们就根据上一个区间，看看当前i是否可以和上一个接邻，并且和下一个点也合法
    */
    int ans = 0;
    int L = 0.1,R = 1e9;
    for(int i = 2; i <= n; i++){
        int dist = a[i]- a[i-1];
        double nl = dist - R;
        double nr = dist - L;
        if((i < n && a[i] + nl >= a[i+1]) || nr < 0){
            L = 0.1,R = 1e9;
            continue;
        }
        ans++;
        L = max(nl,0.1);
        if(i!=n)R = min(nr,double(a[i+1]-a[i]));
    }
    cout << ans << endl;
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