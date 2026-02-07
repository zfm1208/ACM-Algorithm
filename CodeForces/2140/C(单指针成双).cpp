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
// f(a) = aost + a1 - a2 + a3 - a4 + a5 - a6 + a7 - a8 + ... + an

// 同奇同偶 : 只有cost变化，r-l

// l奇r偶 ：2(ar - al) + r-l;  
// 2 * ar + r - (2 * al + l)

// l偶r奇 ：2(al - ar) + r-l
// 2 * al -l - (2 * ar - r)

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i] * (i&1 ? 1 : -1);
    }
    if(n==1){
        cout << sum << endl;
        return;
    }
    vector<int> mx(n+2),mn(n+2);
    
    mn[1] = 1 + 2 * a[1];
    for(int l = 2; l <= n; l++){
        if(l&1){
            mn[l] = min(mn[l-2],2*a[l]+l);
        }else{
            mx[l] = max(mx[l-2],2*a[l]-l);
        }
    }
    int ans = 0;
    for(int r = 1; r <= n; r++){
        // r 是奇数
        int l = r-1;
        if(r&1){
            ans = max(ans,mx[l] - (2*a[r] -r));
        }else{
            ans = max(ans,2*a[r]+r - mn[l]);
        }
    }
    int l = 1,r = n-1;
    if(n&1) r++;
    ans = max(ans,r-l);
    cout << ans + sum << endl;
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