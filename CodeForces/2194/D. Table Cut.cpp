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
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    int tot = 0;
    rep(i,1,n) rep(j,1,m) {
        cin >> a[i][j];
        if(a[i][j] == 1) tot++;
    }
    int tar = tot / 2;
    cout << tar * (tot - tar) << endl;
    if (tar == 0){
        rep(i, 1, n) cout << 'D';
        rep(i, 1, m) cout << 'R';
        cout << endl;
        return;
    }
    int col = 0, row = 0;
    int sum = 0;
    for(int j = 1; j <= m; j++){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i][j] == 1) cnt++;
        }
        if(cnt + sum <= tar){
            sum += cnt;
            col = j;
            row = 1;            
            if(sum == tar){
                break;
            }
        }else{
            col = j;
            for(int i = n; i >= 1; i--){
                if(a[i][j] == 1) sum++;
                if(sum == tar){
                    row = i;
                    break;
                }
            }
            break;
        }
    }
    rep(i,1,col-1) cout << 'R';
    rep(i,1,row-1) cout << 'D';
    cout << 'R';
    rep(i,1,n-row+1) cout << 'D';
    rep(i,1,m-col) cout << 'R';
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