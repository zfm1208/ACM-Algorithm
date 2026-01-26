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
    int n,m,h; cin >> n >> m >> h;
    vector<vector<int>> a(n+1,vector<int> (m+1));
    vector<array<int,3>> ans(n+1); 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
        sort(a[i].begin()+1,a[i].end());
        int time = 0;
        int fs = 0;
        int fen = 0;
        for(int j = 1; j <= m; j++){
            if(time + a[i][j] <= h){
                time += a[i][j];
                fs += time;
                fen++;
            }
        }
        ans[i] = {fen,fs,i};
    }
    sort(ans.begin()+1,ans.end(),[](auto x, auto y){
        if(x[0] != y[0]) return x[0] > y[0]; 
        if(x[1] != y[1]) return x[1] < y[1]; 
        return x[2] < y[2];  
    });
    for(int i = 1; i <= n; i++){
        if(ans[i][2] == 1){
            cout << i << endl;
            return;
        }
    }
    
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