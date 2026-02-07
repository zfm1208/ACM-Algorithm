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
    vector<pii> a(n+1),b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i%2;
        b[i].fi = a[i].fi;
        b[i].se = 1-a[i].se;
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    bool ok = 0;
    for(int i = 2; i <= n; i++){
        if(a[i].se == a[i-1].se){
            ok = 1;
            break;
        }
    }
    bool ok1 = 0;
    for(int i = 2; i <= n; i++){
        if(b[i].se == b[i-1].se){
            ok1 = 1;
            break;
        }
    }
    if(ok==0 || ok1 == 0){
        cout << "YES" << endl;
    }else cout << "NO" << endl;

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