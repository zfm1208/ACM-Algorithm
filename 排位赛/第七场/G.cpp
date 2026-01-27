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
    int n,m;
    while(cin >> n >> m){
        vector<vector<int>> a(n+1,vector<int> (m+1));
        vector<int> sum(n+1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                sum[i] += a[i][j];
            }
        }
        bool ok = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(abs(sum[i] - sum[j])% 2 == 0){
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
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