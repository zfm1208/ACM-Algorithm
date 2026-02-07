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
    // 先放奇数，剩下的都放偶数
    // 1奇1偶1奇1偶
    // 1奇全偶
    vector<int> ji,ou;
    int mx = 0;
    ou.pb(0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]&1){
            mx = max(mx,a[i]);
            ji.pb(a[i]);
        }else{
            ou.pb(a[i]);
        }
    }
    if(ji.size() == 0){
        rep(i,1,n) cout << 0 << " \n"[i==n];
        return;
    }
    sort(ou.begin()+1,ou.end(),[](int x, int y){
        return x > y;
    });
    vector<int> pre(n+1);
    int nn = ou.size();
    int cnt = ji.size();
    for(int i = 1; i < nn; i++){
        pre[i] = pre[i-1] + ou[i];
    }
    for(int i = 1;i <= n; i++){
        int o = min(i-1,nn-1);
        if((i-o) & 1){
            cout << mx + pre[o] << " ";
        }else{
            // 偶数不够？奇数来凑
            int j = i-o;
            j++;
            o--;
            if(o>=0 && j<=cnt){
                cout << mx + pre[o] << " ";
            }else{
                cout << 0 << " ";
            }
        }
    }
    cout << endl;
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