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

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    map<int,int> mp;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        cin >> a[i][j];
        mp[a[i][j]]++;
    }
    int mx = 0;
    for(auto [x,y]: mp){
        if(y > mx){
            mx = y;
        }
    }
    if(mx > n*(n-1)){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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