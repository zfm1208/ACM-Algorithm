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
    int l = n;
    for(int i = 1; i <= n; i++){
        if(a[i] == l)  l--;
        else{
            for(int j = i+1; j <= n; j++){
                if(a[j] == l){
                    reverse(a.begin()+i,a.begin()+j+1);
                    rep(k,1,n) cout << a[k] << " \n"[k == n];
                    return;                    
                }
            }
            
        }
    }
    rep(k,1,n) cout << a[k] << " \n"[k == n];
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